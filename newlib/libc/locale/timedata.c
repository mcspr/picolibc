/*
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright © 2025 Keith Packard
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#define _DEFAULT_SOURCE
#include "locale_private.h"

#ifndef __STRINGIFY
#define __STRINGIFY(a) #a
#endif

#define PSTR_TIMEDATA(TYPE, NAME)\
    static const char __time_ ## TYPE ## _ ## NAME [] PSTR_ATTR = __STRINGIFY(NAME)

PSTR_TIMEDATA(wday, Sun);
PSTR_TIMEDATA(wday, Mon);
PSTR_TIMEDATA(wday, Tue);
PSTR_TIMEDATA(wday, Wed);
PSTR_TIMEDATA(wday, Thu);
PSTR_TIMEDATA(wday, Fri);
PSTR_TIMEDATA(wday, Sat);

const char *const __time_wday[8] PROGMEM = {
    __time_wday_Sun,
    __time_wday_Mon,
    __time_wday_Tue,
    __time_wday_Wed,
    __time_wday_Thu,
    __time_wday_Fri,
    __time_wday_Sat,
    NULL,
};


PSTR_TIMEDATA(weekday, Sunday);
PSTR_TIMEDATA(weekday, Monday);
PSTR_TIMEDATA(weekday, Tuesday);
PSTR_TIMEDATA(weekday, Wednesday);
PSTR_TIMEDATA(weekday, Thursday);
PSTR_TIMEDATA(weekday, Friday);
PSTR_TIMEDATA(weekday, Saturday);

const char *const __time_weekday[8] PROGMEM = {
    __time_weekday_Sunday,
    __time_weekday_Monday,
    __time_weekday_Tuesday,
    __time_weekday_Wednesday,
    __time_weekday_Thursday,
    __time_weekday_Friday,
    __time_weekday_Saturday,
    NULL,
};

PSTR_TIMEDATA(mon, Jan);
PSTR_TIMEDATA(mon, Feb);
PSTR_TIMEDATA(mon, Mar);
PSTR_TIMEDATA(mon, Apr);
PSTR_TIMEDATA(mon, May);
PSTR_TIMEDATA(mon, Jun);
PSTR_TIMEDATA(mon, Jul);
PSTR_TIMEDATA(mon, Aug);
PSTR_TIMEDATA(mon, Sep);
PSTR_TIMEDATA(mon, Oct);
PSTR_TIMEDATA(mon, Nov);
PSTR_TIMEDATA(mon, Dec);

const char *const __time_mon[13] PROGMEM = {
    __time_mon_Jan,
    __time_mon_Feb,
    __time_mon_Mar,
    __time_mon_Apr,
    __time_mon_May,
    __time_mon_Jun,
    __time_mon_Jul,
    __time_mon_Aug,
    __time_mon_Sep,
    __time_mon_Oct,
    __time_mon_Nov,
    __time_mon_Dec,
    NULL,
};

PSTR_TIMEDATA(month, January);
PSTR_TIMEDATA(month, February);
PSTR_TIMEDATA(month, March);
PSTR_TIMEDATA(month, April);
PSTR_TIMEDATA(month, May);
PSTR_TIMEDATA(month, June);
PSTR_TIMEDATA(month, July);
PSTR_TIMEDATA(month, August);
PSTR_TIMEDATA(month, September);
PSTR_TIMEDATA(month, October);
PSTR_TIMEDATA(month, November);
PSTR_TIMEDATA(month, December);

const char *const __time_month[13] PROGMEM = {
    __time_month_January,
    __time_month_February,
    __time_month_March,
    __time_month_April,
    __time_month_May,
    __time_month_June,
    __time_month_July,
    __time_month_August,
    __time_month_September,
    __time_month_October,
    __time_month_November,
    __time_month_December,
    NULL,
};

PSTR_TIMEDATA(am_pm, AM);
PSTR_TIMEDATA(am_pm, PM);

const char *const __time_am_pm[3] PROGMEM = {
    __time_am_pm_AM,
    __time_am_pm_PM,
    NULL,
};

const wchar_t *const __wtime_wday[7] = {
    L"Sun", L"Mon", L"Tue", L"Wed",
    L"Thu", L"Fri", L"Sat"
};

const wchar_t *const __wtime_weekday[7] = {
    L"Sunday", L"Monday", L"Tuesday", L"Wednesday",
    L"Thursday", L"Friday", L"Saturday"
};

const wchar_t *const __wtime_mon[12] = {
    L"Jan", L"Feb", L"Mar", L"Apr", L"May", L"Jun",
    L"Jul", L"Aug", L"Sep", L"Oct", L"Nov", L"Dec"
};

const wchar_t *const __wtime_month[12] = {
    L"January", L"February", L"March", L"April", L"May", L"June",
    L"July", L"August", L"September", L"October", L"November", L"December"
};

const wchar_t *const __wtime_am_pm[2] = {
    L"AM", L"PM"
};
