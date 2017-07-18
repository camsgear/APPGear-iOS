

#import <Foundation/Foundation.h>
#import <Availability.h>
#import <TargetConditionals.h>

#ifndef _AFNETWORKING_
    #define _AFNETWORKING_

    #import "CLURLRequestSerialization.h"
    #import "CLURLResponseSerialization.h"
    #import "CLSecurityPolicy.h"

#if !TARGET_OS_WATCH
    #import "CLNetworkReachabilityManager.h"
#endif

    #import "CLURLSessionManager.h"
    #import "CLHTTPSessionManager.h"

#endif /* _CLNETWORKING_ */
