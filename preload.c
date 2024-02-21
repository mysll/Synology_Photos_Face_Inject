#include <stdio.h>

// patch libsynophoto-plugin-platform.so 
long long _ZN9synophoto6plugin8platform15IsSupportedFaceEv() {
    return 0LL;
}

// patch libsynophoto-plugin-model.so
long long _ZN9synophoto6plugin7network9IeNetwork11IsSupportedEv() {
    return 0LL;
}

__attribute__((constructor)) void main() {
    printf("module inject success\n");
}
