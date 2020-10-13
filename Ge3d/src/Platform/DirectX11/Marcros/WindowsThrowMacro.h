#pragma once

#define GEHWND_EXCEPT( hr ) GE::Win32Window::HrException( __LINE__,__FILE__,(hr) )
#define GEHWND_LAST_EXCEPT() GE::Win32Window::HrException( __LINE__,__FILE__,GetLastError() )
#define GEHWND_NOGFX_EXCEPT() GE::Win32Window::NoGfxException( __LINE__,__FILE__ )
