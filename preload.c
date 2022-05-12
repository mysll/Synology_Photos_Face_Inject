#include <stdio.h>

long long _ZN9synophoto6plugin7network9IeNetwork11IsSupportedEv() {
    printf("synophoto::plugin::network::IeNetwork::IsSupported return 0\n");
    return 0LL;
}

__attribute__((constructor)) void main() {
    printf("module inject success\n");
}
