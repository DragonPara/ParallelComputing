# MPI环境管理函数

  * MPI_Init
  * MPI_Comm_size
  * MPI_Comm_rank
  * MPI_Abort
  * MPI_Get_processor_name
  * MPI_Initialized
  * MPI_Wtime
  * MPI_Wtick
  * MPI_Finalize
# 点对点通信
## 阻塞消息通信函数
  * MPI_Send
  * MPI_Recv
  * MPI_Ssend
  * MPI_Bsend
  * MPI_Buffer_attach, MPI_Buffer_detach
  * MPI_Rsend
  * MPI_Sendrecv
  * MPI_Wait, MPI_Waitany, MPI_Waitall, MPI_Waitsome
  * MPI_Probe
## 非阻塞消息通信函数
  * MPI_Isend
  * MPI_Irecv
  * MPI_Issend
  * MPI_Ibsend
  * MPI_Irsend
  * MPI_Test, MPI_Testany, MPI_Testall, MPI_Testsome
  * MPI_Iprobe

# 集合通信函数
  * MPI_Barrier
  * MPI_Gather
  * MPI_Allgather
  * MPI_Reduce
  * MPI_Allreduce
  * MPI_Reduce_scatter
  * MPI_Alltoall
  * MPI_Scan

# 派生数据类型函数
  * MPI_Type_contiguous
  * MPI_Type_vector, MPI_Type_hvector
  * MPI_type_indexed, MPI_Type_hindexed
  * MPI_Type_struct
  * MPI_Type_extent
  * MPI_Type_commit

# 组和通讯因子管理函数
  * MPI_Comm_group
  * MPI_Group_rank
  * MPI_Group_size
  * MPI_Group_excl
  * MPI_Group_incl
  * MPI_Group_intersection
  * MPI_Group_union
  * MPI_Group_difference
  * MPI_Group_compare
  * MPI_Group_free
  * MPI_Comm_create
  * MPI_Comm_dup
  * MPI_Comm_compare
  * MPI_Comm_free
# 虚拟拓扑函数
  * MPI_Cart_coords
  * MPI_Cart_create
  * MPI_Cart_get
  * MPI_Cart_map
  * MPI_Cart_rank
  * MPI_Cart_Shift
  * MPI_Cart_sub
  * MPI_Cartdim_get
  * MPI_Dims_create
  * MPI_Graph_get
  * MPI_Graph_map
  * MPI_Graph_nerighbors
  * MPI_Graphdims_get
  * MPI_Topo_test