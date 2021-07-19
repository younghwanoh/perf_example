## Perf profiler code sniphet for only profiling region-of-interests

## Install perf
``` bash
# For up-to-date kernels
sudo apt-get install linux-tools-common

# For a specific version of linux kernels
sudo apt-get install linux-tools-4.15.0-142-generic

# Make the example and run
make
./example
```

## Paranoid setup for performance monitoring
If following messages are popped up, just follow the instruction
```
Error:
You may not have permission to collect stats.

Consider tweaking /proc/sys/kernel/perf_event_paranoid,
which controls use of the performance events system by
unprivileged users (without CAP_SYS_ADMIN).

The current value is 3:

  -1: Allow use of (almost) all events by all users
      Ignore mlock limit after perf_event_mlock_kb without CAP_IPC_LOCK
>= 0: Disallow ftrace function tracepoint by users without CAP_SYS_ADMIN
      Disallow raw tracepoint access by users without CAP_SYS_ADMIN
>= 1: Disallow CPU event access by users without CAP_SYS_ADMIN
>= 2: Disallow kernel profiling by users without CAP_SYS_ADMIN

To make this setting permanent, edit /etc/sysctl.conf too, e.g.:

kernel.perf_event_paranoid = -1
```
