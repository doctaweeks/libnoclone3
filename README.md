Use [libseccomp](https://github.com/seccomp/libseccomp) to force glibc to use
clone instead of clone3 at runtime.

To use, preload libnoclone3 and set NOCLONE3 in the environment, ex:
    
    NOCLONE3=1 LD_PRELOAD=/tmp/libnoclone3.so.0.0.0 vim
