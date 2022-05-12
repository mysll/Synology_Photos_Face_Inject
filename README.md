# Synology_Photos_Face_Inject
synology photos 使用cpu进行人脸识别,使用这个方法可以随意升级，不会破坏原有应用

refer: [https://github.com/jinlife/Synology_Photos_Face_Patch]

准备工作:
   - 需要gcc编译环境，可以安装debian chroot
   - 或者使用 docker: docker pull gcc
   
## step1:
创建一个文件preload.c，内容如下

```
#include <stdio.h>

long long _ZN9synophoto6plugin7network9IeNetwork11IsSupportedEv() {
    printf("synophoto::plugin::network::IeNetwork::IsSupported return 0\n");
    return 0LL;
}

__attribute__((constructor)) void main() {
    printf("module inject success\n");
}
```

## step2:
直接使用gcc编译
```
gcc -fPIC -shared -o preload.so preload.c
```
使用 docker gcc 进行编译
```
docker run --rm -v "$PWD":/usr/src/preload -w /usr/src/preload gcc gcc -fPIC -shared -o preload.so preload.c
```

## step3
安装
```
cp preload.so /usr/lib/preload.so
```

## step4
修改 pkg-SynologyPhotos-face-extraction.service
在Service段中增加环境变量
```
[Service]
Environment="LD_PRELOAD=preload.so"
```
最后重启一下服务
```
systemctl restart pkg-SynologyPhotos-face-extraction
```




