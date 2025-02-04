// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.

#pragma once

#include "pal_compiler.h"
#include "pal_types.h"
#include "pal_errno.h"

PALEXPORT int32_t SystemNative_TeamInfo(int32_t id, void* info, size_t size);
PALEXPORT int32_t SystemNative_NextAreaInfo(int32_t id, int64_t* cookie, void* info, size_t size);
