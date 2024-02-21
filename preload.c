#include <stdio.h>

// patch libsynophoto-plugin-platform.so 
long long _ZN9synophoto6plugin8platform20IsSupportedIENetworkEv() {
    return 0LL;
}

long long _ZN9synophoto6plugin8platform18IsSupportedConceptEv() {
	return 1LL;
}

long long _ZN9synophoto6plugin8platform23IsSupportedIENetworkGpuEv() {
	return 0LL;
}


__attribute__((constructor)) void main() {
    printf("module inject success\n");
}
