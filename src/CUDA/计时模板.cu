cudaEvent_t start, stop;
CHECK(cudaEventCreate(&start));
CHECK(cudaEventCreate(&stop));
CHECK(cudaEventRecord(start));//Record 记录
cudaEventQuery(start);//Can't Check
/*
    需要计时的代码块
*/
CHECK(cudaEventRecord(stop));
CHECK(cudaEventSynchronize(stop));
float elapsed_time; //elapesd 过去的  adj.
CHECK(cudaEventElapsedTime(&elapsed_time, start, stop));
printf("Time = %g ms.\n",elapsed_time);
CHECK(cudaEventDestory(start));
CHECK(cudaEventDestory(stop));
