/*
 * Copyright (c) 2020 ZenDIY
 * All rights reserved
 *
 * Licensed under the Apache License, Version 2.0 (the ""License"");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an ""AS IS"" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MGOS_ZTHING_UTILS_H_
#define MGOS_ZTHING_UTILS_H_

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Count recurrences of str2 in str1 */
int mgos_zthing_scount(const char *str1, const char* str2);

/* TODO: comment */
bool mgos_zthing_sreplace(const char *src, const char *str,
                          const char* replace_with, char **out);

/* TODO: comment */
bool mgos_zthing_sreplaces(const char *src, char **out,
                           int count, ...);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MGOS_ZTHING_UTILS_H_ */