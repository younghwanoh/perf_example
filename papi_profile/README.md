## Download and install PAPI from official repo
[Official site link](http://icl.utk.edu/papi/)

```
tar xvzf papi-5.7.0.tar.gz
cd papi-5.7.0/src
./configure
make
sudo make install-all
```

## Caveat: Use the right version
For above github repo of papi-5.7.0, different high-level API is used. (Master branch of github)
Instead, use `papi-5.7.0.tar.gz` in this folder for use of legacy API, which is more stable.

## Caveat: Change the security settings
To enable many important metrics, you have to change perf security settings.
Otherwise, you may get errors after profile some metrics.

```
# Reboot required
echo kernel.perf_event_paranoid=-1 >> /etc/sysctl.conf
```
