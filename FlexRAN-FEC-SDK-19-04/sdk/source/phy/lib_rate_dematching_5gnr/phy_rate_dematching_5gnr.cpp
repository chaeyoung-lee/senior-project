/**********************************************************************
 *
 * INTEL CONFIDENTIAL
 * Copyright 2009-2019 Intel Corporation All Rights Reserved.
 * 
 * The source code contained or described herein and all documents related to the
 * source code ("Material") are owned by Intel Corporation or its suppliers or
 * licensors. Title to the Material remains with Intel Corporation or its
 * suppliers and licensors. The Material may contain trade secrets and proprietary
 * and confidential information of Intel Corporation and its suppliers and
 * licensors, and is protected by worldwide copyright and trade secret laws and
 * treaty provisions. No part of the Material may be used, copied, reproduced,
 * modified, published, uploaded, posted, transmitted, distributed, or disclosed
 * in any way without Intel's prior express written permission.
 * 
 * No license under any patent, copyright, trade secret or other intellectual
 * property right is granted to or conferred upon you by disclosure or delivery
 * of the Materials, either expressly, by implication, inducement, estoppel or
 * otherwise. Any license under such intellectual property rights must be
 * express and approved by Intel in writing.
 * 
 * Unless otherwise agreed by Intel in writing, you may not remove or alter this
 * notice or any other notice embedded in Materials by Intel or Intel's suppliers
 * or licensors in any way.
 * 
 *  version: SDK-jenkins-FlexRAN-SDK-REL-448-g3be238
 *
 **********************************************************************/

/*
 * @file
 * @brief  Source code of External API for rate dematching functions
 */

#include <functional>
#include <cstdio>

#include "phy_rate_dematching_5gnr.h"
#include "sdk_version.h"

typedef void (*rate_dematching_5gnr_function)(struct bblib_rate_dematching_5gnr_request *request,
                                            struct bblib_rate_dematching_5gnr_response *response);


void bblib_print_rate_dematching_5gnr_version() {
    static bool was_executed = false;
    if (!was_executed) {
        was_executed = true;
        char version[BBLIB_SDK_VERSION_STRING_MAX_LEN] = { };
        bblib_rate_dematching_5gnr_version(version, sizeof(version));
        printf("%s\n", version);
    }
}

struct bblib_rate_dematching_5gnr_init
{
    bblib_rate_dematching_5gnr_init()
    {
        bblib_print_rate_dematching_5gnr_version();
    }
};

bblib_rate_dematching_5gnr_init do_constructor_rate_dematching_5gnr;

/** Return a pointer-to-function for a specific implementation */
static rate_dematching_5gnr_function bblib_rate_dematching_5gnr_select_on_isa() {

#ifdef _BBLIB_AVX512_
    return bblib_rate_dematching_5gnr_avx512;
#else
    return bblib_rate_dematching_5gnr_c;
#endif

}

static rate_dematching_5gnr_function default_rate_dematching_5gnr = bblib_rate_dematching_5gnr_select_on_isa();

void bblib_rate_dematching_5gnr(struct bblib_rate_dematching_5gnr_request *request,
        struct bblib_rate_dematching_5gnr_response *response) {
    return default_rate_dematching_5gnr(request, response);
}

int16_t bblib_rate_dematching_5gnr_version(char *version, int buffer_size) {
    /* The version string will be updated before the build process starts  by the
     *       jobs building the library and/or preparing the release packages.
     *       Do not edit the version string manually */
    const char *msg = "FlexRAN SDK bblib_lte_rate_dematching_5gnr version sdk-19.04-ea1-1-g3be2380";

    return (bblib_sdk_version(&version, &msg, buffer_size));
}

