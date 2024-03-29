/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/control_panel/functions.h
 *
 * Purpose:     Control Panel functions.
 *
 * Created:     1st April 2006
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2006-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Information Systems
 *   nor the names of any contributors may be used to endorse or promote
 *   products derived from this software without specific prior written
 *   permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file winstl/control_panel/functions.h
 *
 * \brief [C, C++] Control Panel functions
 *   (\ref group__library__Windows_ControlPanel "Windows Control Panel" Library).
 */

#ifndef WINSTL_INCL_WINSTL_CONTROL_PANEL_H_FUNCTIONS
#define WINSTL_INCL_WINSTL_CONTROL_PANEL_H_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_CONTROL_PANEL_H_FUNCTIONS_MAJOR      1
# define WINSTL_VER_WINSTL_CONTROL_PANEL_H_FUNCTIONS_MINOR      0
# define WINSTL_VER_WINSTL_CONTROL_PANEL_H_FUNCTIONS_REVISION   13
# define WINSTL_VER_WINSTL_CONTROL_PANEL_H_FUNCTIONS_EDIT       28
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_H_CPL
# define STLSOFT_INCL_H_CPL
# include <cpl.h>
#endif /* !STLSOFT_INCL_H_CPL */

#ifndef WINSTL_INCL_WINSTL_API_external_h_UnicodeAndCharacterSet
# include <winstl/api/external/UnicodeAndCharacterSet.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_UnicodeAndCharacterSet */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(WINSTL_NO_NAMESPACE) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# if defined(STLSOFT_NO_NAMESPACE)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */
namespace stlsoft
{
namespace winstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

/** Function pointer representing the entry point provide by all
 *   control panel applet modules.
 */
typedef LONG (APIENTRY *control_panel_entry_t)(HWND , UINT , LPARAM , LPARAM );

/* /////////////////////////////////////////////////////////////////////////
 * C functions
 */

/** [C, C++] Initialises a control panel applet module.
 *
 * \ingroup group__library__Windows_ControlPanel
 */
STLSOFT_INLINE
BOOL
winstl_C_control_panel_init(
    control_panel_entry_t   entry
,   HWND                    hwnd
)
{
    WINSTL_ASSERT(NULL != entry);

    return (*entry)(hwnd, CPL_INIT, 0, 0);
}

/** [C, C++] Uninitialises a control panel applet module.
 *
 * \ingroup group__library__Windows_ControlPanel
 *
 */
STLSOFT_INLINE
void
winstl_C_control_panel_uninit(
    control_panel_entry_t   entry
,   HWND                    hwnd
)
{
    WINSTL_ASSERT(NULL != entry);

    STLSOFT_STATIC_CAST(void, (*entry)(hwnd, CPL_EXIT, 0, 0));
}

/** [C, C++] Retrieves the number of control panel applets within a control panel applet module.
 *
 * \ingroup group__library__Windows_ControlPanel
 *
 */
STLSOFT_INLINE
ss_size_t
winstl_C_control_panel_get_count(
    control_panel_entry_t   entry
,   HWND                    hwnd
)
{
    WINSTL_ASSERT(NULL != entry);

    return STLSOFT_STATIC_CAST(ss_size_t, (*entry)(hwnd, CPL_GETCOUNT, 0, 0));
}

/** [C, C++] Issues an inquiry control (CPL_INQUIRE) to a control panel applet.
 *
 * \ingroup group__library__Windows_ControlPanel
 *
 */
STLSOFT_INLINE
void
winstl_C_control_panel_inquire(
    control_panel_entry_t   entry
,   HWND                    hwnd
,   ss_size_t               index
,   LPCPLINFO               info
)
{
    WINSTL_ASSERT(NULL != entry);
    WINSTL_ASSERT(NULL != info);
    WINSTL_ASSERT(index < winstl_C_control_panel_get_count(entry, hwnd));

    STLSOFT_STATIC_CAST(void, (*entry)(hwnd, CPL_INQUIRE, STLSOFT_STATIC_CAST(LPARAM, index), STLSOFT_REINTERPRET_CAST(LPARAM, info)));
}

/** [C, C++] Issues a "new" inquiry control (CPL_NEWINQUIRE) to a control panel applet.
 *
 * \ingroup group__library__Windows_ControlPanel
 *
 */
STLSOFT_INLINE
void
winstl_C_control_panel_newinquire(
    control_panel_entry_t   entry
,   HWND                    hwnd
,   ss_size_t               index
,   LPNEWCPLINFO            info
)
{
    /* Some applets don't handle sizeof(NEWCPLINFOA), so we try with Unicode first. */
    union
    {
        NEWCPLINFOA infoa_;
        NEWCPLINFOW infow_;
    }       u;

    WINSTL_ASSERT(NULL != entry);
    WINSTL_ASSERT(NULL != info);
    WINSTL_ASSERT(sizeof(NEWCPLINFOA) != info->dwSize || sizeof(NEWCPLINFOW) != info->dwSize);
    WINSTL_ASSERT(index < winstl_C_control_panel_get_count(entry, hwnd));

    u.infoa_.dwFlags        =   0;
    u.infoa_.dwHelpContext  =   0;
    u.infoa_.lData          =   0;
    u.infoa_.hIcon          =   NULL;
    u.infoa_.szName[0]      =   L'\0';
    u.infoa_.szInfo[0]      =   L'\0';
    u.infoa_.szHelpFile[0]  =   L'\0';
    u.infow_.szName[0]      =   L'\0';
    u.infow_.szInfo[0]      =   L'\0';
    u.infow_.szHelpFile[0]  =   L'\0';

    if (sizeof(NEWCPLINFOW) == info->dwSize)
    {
        /* Try Unicode first. */
        LPNEWCPLINFOW infow = STLSOFT_REINTERPRET_CAST(LPNEWCPLINFOW, info);

        u.infow_.dwSize = sizeof(NEWCPLINFOW);

        STLSOFT_STATIC_CAST(void, (*entry)(hwnd, CPL_NEWINQUIRE, STLSOFT_STATIC_CAST(LPARAM, index), STLSOFT_REINTERPRET_CAST(LPARAM, &u.infow_)));

        if (u.infow_.dwSize == sizeof(NEWCPLINFOW) &&
            L'\0' != u.infow_.szName[0])
        {
            *infow = u.infow_;
        }
        else
        {
            /* Unicode failed, so try ANSI. */
            u.infoa_.dwSize = sizeof(NEWCPLINFOA);

            STLSOFT_STATIC_CAST(void, (*entry)(hwnd, CPL_NEWINQUIRE, STLSOFT_STATIC_CAST(LPARAM, index), STLSOFT_REINTERPRET_CAST(LPARAM, &u.infoa_)));

            WINSTL_API_EXTERNAL_UnicodeAndCharacterSet_MultiByteToWideChar(0, 0, u.infoa_.szName, -1, infow->szName, STLSOFT_NUM_ELEMENTS(u.infow_.szName));
            WINSTL_API_EXTERNAL_UnicodeAndCharacterSet_MultiByteToWideChar(0, 0, u.infoa_.szInfo, -1, infow->szInfo, STLSOFT_NUM_ELEMENTS(u.infow_.szInfo));
            WINSTL_API_EXTERNAL_UnicodeAndCharacterSet_MultiByteToWideChar(0, 0, u.infoa_.szHelpFile, -1, infow->szHelpFile, STLSOFT_NUM_ELEMENTS(u.infow_.szHelpFile));
        }
    }
    else
    {
        /* Try ANSI first. */
        LPNEWCPLINFOA infoa = STLSOFT_REINTERPRET_CAST(LPNEWCPLINFOA, info);

        u.infoa_.dwSize = sizeof(NEWCPLINFOA);

        STLSOFT_STATIC_CAST(void, (*entry)(hwnd, CPL_NEWINQUIRE, STLSOFT_STATIC_CAST(LPARAM, index), STLSOFT_REINTERPRET_CAST(LPARAM, &u.infoa_)));

        if (u.infoa_.dwSize == sizeof(NEWCPLINFOA) &&
            '\0' != u.infoa_.szName[0])
        {
            *infoa = u.infoa_;
        }
        else
        {
            /* ANSI failed, so try Unicode. */
            u.infow_.dwSize = sizeof(NEWCPLINFOW);

            STLSOFT_STATIC_CAST(void, (*entry)(hwnd, CPL_NEWINQUIRE, STLSOFT_STATIC_CAST(LPARAM, index), STLSOFT_REINTERPRET_CAST(LPARAM, &u.infow_)));

            WINSTL_API_EXTERNAL_UnicodeAndCharacterSet_WideCharToMultiByte(0, 0, u.infow_.szName, -1, infoa->szName, STLSOFT_NUM_ELEMENTS(u.infoa_.szName), NULL, NULL);
            WINSTL_API_EXTERNAL_UnicodeAndCharacterSet_WideCharToMultiByte(0, 0, u.infow_.szInfo, -1, infoa->szInfo, STLSOFT_NUM_ELEMENTS(u.infoa_.szInfo), NULL, NULL);
            WINSTL_API_EXTERNAL_UnicodeAndCharacterSet_WideCharToMultiByte(0, 0, u.infow_.szHelpFile, -1, infoa->szHelpFile, STLSOFT_NUM_ELEMENTS(u.infoa_.szHelpFile), NULL, NULL);
        }
    }
}

/** [C, C++] Issues a run control (CPL_DBLCLK) to a control panel applet, including caller-supplied data.
 *
 * \ingroup group__library__Windows_ControlPanel
 *
 */
STLSOFT_INLINE
BOOL
winstl_C_control_panel_run_data(
    control_panel_entry_t   entry
,   HWND                    hwnd
,   ss_size_t               index
,   LPARAM                  data
)
{
    WINSTL_ASSERT(NULL != entry);

    return !STLSOFT_STATIC_CAST(BOOL, (*entry)(hwnd, CPL_DBLCLK, index, data));
}

/** [C, C++] Issues a run control (CPL_STARTWPARMSA) to a control panel applet, including caller-supplied parameter string.
 *
 * \ingroup group__library__Windows_ControlPanel
 *
 */
STLSOFT_INLINE
BOOL
winstl_C_control_panel_run_params_a(
    control_panel_entry_t   entry
,   HWND                    hwnd
,   ss_size_t               index
,   ws_char_a_t const*      params
)
{
    WINSTL_ASSERT(NULL != entry);

    return STLSOFT_STATIC_CAST(BOOL, (*entry)(hwnd, CPL_STARTWPARMSA, STLSOFT_STATIC_CAST(LPARAM, index), (LPARAM)params));
}

/** [C, C++] Issues a run control (CPL_STARTWPARMSW) to a control panel applet, including caller-supplied parameter string.
 *
 * \ingroup group__library__Windows_ControlPanel
 *
 */
STLSOFT_INLINE
BOOL
winstl_C_control_panel_run_params_w(
    control_panel_entry_t   entry
,   HWND                    hwnd
,   ss_size_t               index
,   ws_char_w_t const*      params
)
{
    WINSTL_ASSERT(NULL != entry);

    return STLSOFT_STATIC_CAST(BOOL, (*entry)(hwnd, CPL_STARTWPARMSW, STLSOFT_STATIC_CAST(LPARAM, index), (LPARAM)params));
}

/** [C, C++] Issues a stop control (CPL_STOP) to a control panel applet.
 *
 * \ingroup group__library__Windows_ControlPanel
 *
 */
STLSOFT_INLINE
void
winstl_C_control_panel_stop(
    control_panel_entry_t   entry
,   HWND                    hwnd
,   ss_size_t               index
,   LPARAM                  data
)
{
    WINSTL_ASSERT(NULL != entry);

    STLSOFT_STATIC_CAST(void, (*entry)(hwnd, CPL_STOP, index, data));
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
namespace winstl
{
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

/* /////////////////////////////////////////////////////////////////////////
 *
 */

/** Initialises a control panel applet module.
 *
 * \ingroup group__library__Windows_ControlPanel
 */
inline
BOOL
control_panel_init(
    control_panel_entry_t   entry
,   HWND                    hwnd
)
{
    return winstl_C_control_panel_init(entry, hwnd);
}

/** Uninitialises a control panel applet module.
 *
 * \ingroup group__library__Windows_ControlPanel
 *
 */
inline
void
control_panel_uninit(
    control_panel_entry_t   entry
,   HWND                    hwnd
)
{
    winstl_C_control_panel_uninit(entry, hwnd);
}

/** Retrieves the number of control panel applets within a control panel applet module.
 *
 * \ingroup group__library__Windows_ControlPanel
 *
 */
inline
ss_size_t
control_panel_get_count(
    control_panel_entry_t   entry
,   HWND                    hwnd
)
{
    return winstl_C_control_panel_get_count(entry, hwnd);
}

/** Issues an inquiry control (CPL_INQUIRE) to a control panel applet.
 *
 * \ingroup group__library__Windows_ControlPanel
 *
 */
inline
void
control_panel_inquire(
    control_panel_entry_t   entry
,   HWND                    hwnd
,   ss_size_t               index
,   LPCPLINFO               info
)
{
    winstl_C_control_panel_inquire(entry, hwnd, index, info);
}

/** Issues a "new" inquiry control (CPL_NEWINQUIRE) to a control panel applet.
 *
 * \ingroup group__library__Windows_ControlPanel
 *
 */
inline
void
control_panel_newinquire(
    control_panel_entry_t   entry
,   HWND                    hwnd
,   ss_size_t               index
,   LPNEWCPLINFO            info
)
{
    winstl_C_control_panel_newinquire(entry, hwnd, index, info);
}

/** Issues a run control (CPL_DBLCLK) to a control panel applet, including caller-supplied data.
 *
 * \ingroup group__library__Windows_ControlPanel
 *
 */
inline
BOOL
control_panel_run_data(
    control_panel_entry_t   entry
,   HWND                    hwnd
,   ss_size_t               index
,   LPARAM                  data
)
{
    return winstl_C_control_panel_run_data(entry, hwnd, index, data);
}

/** Issues a run control (CPL_STARTWPARMSA) to a control panel applet, including caller-supplied parameter string.
 *
 * \ingroup group__library__Windows_ControlPanel
 *
 */
inline
BOOL
control_panel_run_params_a(
    control_panel_entry_t   entry
,   HWND                    hwnd
,   ss_size_t               index
,   ws_char_a_t const*      params
)
{
    return winstl_C_control_panel_run_params_a(entry, hwnd, index, params);
}

/** Issues a run control (CPL_STARTWPARMSW) to a control panel applet, including caller-supplied parameter string.
 *
 * \ingroup group__library__Windows_ControlPanel
 *
 */
inline
BOOL
control_panel_run_params_w(
    control_panel_entry_t   entry
,   HWND                    hwnd
,   ss_size_t               index
,   ws_char_w_t const*      params
)
{
    return winstl_C_control_panel_run_params_w(entry, hwnd, index, params);
}

/** Issues a run control (CPL_DBLCLK) to a control panel applet, including caller-supplied data.
 *
 * \ingroup group__library__Windows_ControlPanel
 *
 */
inline
BOOL
control_panel_run(
    control_panel_entry_t   entry
,   HWND                    hwnd
,   ss_size_t               index
,   LPARAM                  data
)
{
    return control_panel_run_data(entry, hwnd, index, data);
}

/** Issues a run control (CPL_STARTWPARMSA) to a control panel applet, including caller-supplied parameter string.
 *
 * \ingroup group__library__Windows_ControlPanel
 *
 */
inline
BOOL
control_panel_run(
    control_panel_entry_t   entry
,   HWND                    hwnd
,   ss_size_t               index
,   ws_char_a_t const*      params
)
{
    return control_panel_run_params_a(entry, hwnd, index, params);
}

/** Issues a run control (CPL_STARTWPARMSW) to a control panel applet, including caller-supplied parameter string.
 *
 * \ingroup group__library__Windows_ControlPanel
 *
 */
inline
BOOL
control_panel_run(
    control_panel_entry_t   entry
,   HWND                    hwnd
,   ss_size_t               index
,   ws_char_w_t const*      params
)
{
    return control_panel_run_params_w(entry, hwnd, index, params);
}

/** Issues a stop control (CPL_STOP) to a control panel applet.
 *
 * \ingroup group__library__Windows_ControlPanel
 *
 */
inline
void
control_panel_stop(
    control_panel_entry_t   entry
,   HWND                    hwnd
,   ss_size_t               index
,   LPARAM                  data
)
{
    winstl_C_control_panel_stop(entry, hwnd, index, data);
}

/* ////////////////////////////////////////////////////////////////////// */

#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_CONTROL_PANEL_H_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

