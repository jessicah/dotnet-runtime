// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.

#pragma once

#include "pal_compiler.h"
#include "pal_types.h"

typedef enum
{
    None = -1,
    AddressAdded = 0,
    AddressRemoved = 1,
    AvailabilityChanged = 2,
} NetworkChangeKind;

typedef void (*NetworkChangeEvent)(int32_t sock, NetworkChangeKind notificationKind);

PALEXPORT void SystemNative_ReadEvents(int32_t sock, NetworkChangeEvent onNetworkChange) __attribute__((noreturn));

PALEXPORT Error SystemNative_CreateNetworkChangeListenerSocket(int32_t* retSocket);

PALEXPORT Error SystemNative_CloseNetworkChangeListenerSocket(int32_t socket);
