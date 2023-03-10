#######################################################################
#
# INTEL CONFIDENTIAL
# Copyright 2009-2019 Intel Corporation All Rights Reserved.
# 
# The source code contained or described herein and all documents related to the
# source code ("Material") are owned by Intel Corporation or its suppliers or
# licensors. Title to the Material remains with Intel Corporation or its
# suppliers and licensors. The Material may contain trade secrets and proprietary
# and confidential information of Intel Corporation and its suppliers and
# licensors, and is protected by worldwide copyright and trade secret laws and
# treaty provisions. No part of the Material may be used, copied, reproduced,
# modified, published, uploaded, posted, transmitted, distributed, or disclosed
# in any way without Intel's prior express written permission.
# 
# No license under any patent, copyright, trade secret or other intellectual
# property right is granted to or conferred upon you by disclosure or delivery
# of the Materials, either expressly, by implication, inducement, estoppel or
# otherwise. Any license under such intellectual property rights must be
# express and approved by Intel in writing.
# 
# Unless otherwise agreed by Intel in writing, you may not remove or alter this
# notice or any other notice embedded in Materials by Intel or Intel's suppliers
# or licensors in any way.
# 
#  version: SDK-jenkins-FlexRAN-SDK-REL-448-g3be238
#
#######################################################################
# To add a new kernel insert an entry in the appropriate list below.
# Please keep lists in alphabetical order and obey naming conventions

# Commom kernels (lte || 5gnr || all)
set(COMMON_KERNELS
  common
  crc
  turbo
  rate_matching
)
# LTE kernels (lte || all)
set(LTE_KERNELS
)
# 5GNR kernels (5gnr || all)
set(5GNR_KERNELS
  LDPC_ratematch_5gnr
  rate_dematching_5gnr
  ldpc_encoder_5gnr
  ldpc_decoder_5gnr
)
# Other kernels (all)
set(OTHER_KERNELS
)
