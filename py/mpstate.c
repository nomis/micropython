/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 Damien P. George
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "py/mpstate.h"

#include <stdlib.h>

#if MICROPY_DYNAMIC_COMPILER
MP_IPT mp_dynamic_compiler_t mp_dynamic_compiler = {0};
#endif

#if MICROPY_INSTANCE_PER_THREAD
MP_IPT mp_state_ctx_t *mp_state_ctx;
#else
mp_state_ctx_t mp_state_ctx;
#endif

#if MICROPY_INSTANCE_PER_THREAD
int mp_state_init(void) {
    mp_state_ctx = malloc(sizeof(*mp_state_ctx));
    if (!mp_state_ctx)
        return -1;

    memset(mp_state_ctx, 0, sizeof(*mp_state_ctx));
    return 0;
}

void mp_state_free(void) {
    if (!mp_state_ctx)
        return;

    memset(mp_state_ctx, 0, sizeof(*mp_state_ctx));
    free(mp_state_ctx);
    mp_state_ctx = NULL;
}
#endif
