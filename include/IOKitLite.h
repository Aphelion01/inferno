//
// IOKitLite
//

#ifndef _IOKitLite_H_
#define _IOKitLite_H_

#pragma once

#include <CoreFoundation/CoreFoundation.h>
#include <mach/mach.h>

/* IOKit definitions */
typedef mach_port_t io_object_t;
typedef io_object_t io_service_t;
typedef io_object_t io_connect_t;
typedef io_object_t io_iterator_t;
typedef uint32_t OSKextDiagnosticsFlags;
typedef uint32_t IOReturn;
typedef kern_return_t OSReturn;
    
/* The IOKit Family featuring The IOKit Master Port */
extern const mach_port_t kIOMasterPortDefault;

OSReturn OSKextSendPersonalitiesToKernel(CFArrayRef personalities);
io_service_t IOServiceGetMatchingService(mach_port_t, CFDictionaryRef matching);
kern_return_t IOServiceGetMatchingServices(mach_port_t, CFDictionaryRef, io_iterator_t *);
kern_return_t IOServiceClose(io_connect_t);
kern_return_t IOObjectRelease(io_object_t);
CFMutableDictionaryRef IOServiceNameMatching(const char *);
kern_return_t IOMasterPort(mach_port_t, mach_port_t *);
io_object_t IOIteratorNext(io_iterator_t);
kern_return_t IOServiceOpen(io_service_t, task_port_t, uint32_t, io_connect_t *);
kern_return_t IOConnectCallStructMethod(mach_port_t, uint32_t, const void *, size_t, void *, size_t *);
kern_return_t IOConnectCallScalarMethod(mach_port_t, uint32_t, const uint64_t *, uint32_t, uint64_t *, uint32_t *);
CFArrayRef OSKextCopyAllRequestedIdentifiers();
CFDataRef IOCFSerialize(CFTypeRef object, CFOptionFlags options);
CFDictionaryRef OSKextCopyLoadedKextInfo(CFArrayRef kextIdentifiers, CFArrayRef infoKeys);

#endif
