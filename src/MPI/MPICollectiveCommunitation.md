## ***The first error I meet***

> Can't launch

**message:**

```shell
mpiexec_***: cannot connect to local mpd (/tmp/mpd2.console_***); possible causes:
  1. no mpd is running on this host
  2. an mpd is running but was started without a "console" (-n option)
In case 1, you can start an mpd on this host with:
    mpd &
and you will be able to run jobs just on this host.
For more details on starting mpds on a set of hosts, see
the MPICH2 Installation Guide.
```

Something go wrong, looks like mpd2.console_*** Can't find.

#### **How to solve the problem?**

mpd2.console is not create by our, it's create by System.

The first step: `$ mpdboot`

Input the command will let CPU hand in hand, become a circle.

#### **mpd2.console_has already be created.**

Now, you can launch `mpicc -o x x.c`

and launch `mpiexec -n number ./x`

## BroadCast

`int MPI_Bcast(void *buf, int count, MPI_Datatype datatype, int source, MPI_Comm common)`

* `*buf`The data's first location, the value is What you want to BroadCast to all the processors.
* `count`How much data will be broadcast.

* `datatype`data's type
* `source`the data from which processor.

* `common`MPI_COMM_WORLD is enough

<text>The first time, I think the source is data, no no no,source is a number of processor.</text>

