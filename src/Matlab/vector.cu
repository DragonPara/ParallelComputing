#include "cuda_runtime.h"
#include "mex.h"
/* Kernel to square elements of the array on the GPU */
__global__ void square_elements(float *in, float *out, int N)
{
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < N)
        out[idx] = in[idx] * in[idx];
}
/* Gateway function */
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    int i, j, m, n;
    double *data1, *data2;
    float *data1f, *data2f;
    float *data1f_gpu, *data2f_gpu;
    mxClassID category;
    if (nrhs != nlhs)
        mexErrMsgTxt("The number of input and output arguments must be the same.");
    for (i = 0; i < nrhs; i++)
    {
        /* Find the dimensions of the data */
        m = mxGetM(prhs[i]);
        n = mxGetN(prhs[i]);
        /* Create an mxArray for the output data */
        plhs[i] = mxCreateDoubleMatrix(m, n, mxREAL);
        /* Create an input and output data array on the GPU*/
        cudaMalloc((void **)&data1f_gpu, sizeof(float) * m * n);
        cudaMalloc((void **)&data2f_gpu, sizeof(float) * m * n);
        /* Retrieve the input data */
        data1 = mxGetPr(prhs[i]);
        /* Check if the input array is single or double precision */
        category = mxGetClassID(prhs[i]);
        if (category == mxSINGLE_CLASS)
        {
            /* The input array is single precision, it can be sent directly to the card */
            cudaMemcpy(data1f_gpu, data1, sizeof(float) * m * n, cudaMemcpyHostToDevice);
        }
        if (category == mxDOUBLE_CLASS)
        {
            /* The input array is in double precision, it needs to be converted to floats before being sent to the card */
            data1f = (float *)mxMalloc(sizeof(float) * m * n);
            for (j = 0; j < m * n; j++)
            {
                data1f[j] = (float)data1[j];
            }
            cudaMemcpy(data1f_gpu, data1f, sizeof(float) * n * m, cudaMemcpyHostToDevice);
        }
        data2f = (float *)mxMalloc(sizeof(float) * m * n);
        /* Compute execution configuration using 128 threads per block */
        dim3 dimBlock(128);
        dim3 dimGrid((m * n) / dimBlock.x);
        if ((n * m) % 128 != 0)
            dimGrid.x += 1;
        /* Call function on GPU */
        square_elements<<<dimGrid, dimBlock>>>(data1f_gpu, data2f_gpu, n * m);
        /* Copy result back to host */
        cudaMemcpy(data2f, data2f_gpu, sizeof(float) * n * m, cudaMemcpyDeviceToHost);
        /* Create a pointer to the output data */
        data2 = mxGetPr(plhs[i]);
        /* Convert from single to double before returning */
        for (j = 0; j < m * n; j++)
        {
            data2[j] = (double)data2f[j];
        }
        /* Clean-up memory on device and host */
        mxFree(data1f);
        mxFree(data2f);
        cudaFree(data1f_gpu);
        cudaFree(data2f_gpu);
    }
}
