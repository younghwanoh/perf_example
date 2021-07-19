#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int global_cnt = 0;

#define ROI_init(layer_name_) int global_cnt_##layer_name_ = 0;

#define ROI_start(layer_name_) {\
      int pid= getpid();\
      int cpid = fork();\
      if (cpid == 0){\
        char buf[100];\
        sprintf(buf, "perf stat -e LLC-loads,LLC-load-misses -p %d > stat-%s%d.log 2>&1",\
        pid, #layer_name_, global_cnt_##layer_name_);\
        execl("/bin/sh", "sh", "-c", buf, NULL);\
      } else {\
        setpgid(cpid, 0);\
}

#define ROI_end(layer_name_) {\
        usleep(10000);\
        kill(-cpid, SIGINT);\
        global_cnt_##layer_name_++;\
      }\
}

ROI_init(conv)
int main(){
  ROI_start(conv)
  // Application start
  sleep(1);
  // Application end
  ROI_end(conv)
}
