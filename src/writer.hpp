#ifndef EGLINFO_WRITER_HPP
#define EGLINFO_WRITER_HPP

#include <EGL/egl.h>
#include "egl_config.hpp"


namespace eglinfo
{


class writer
{
public:
	virtual void begin_write() = 0;
	virtual void end_write() = 0;
	
	virtual void next_api() = 0;

	virtual void write_main_egl_info(
		  EGLint const p_major_version, EGLint const p_minor_version
		, char const *p_vendor
		, char const *p_version
		, char const *p_client_APIs
		, char const *p_extensions
	) = 0;

	virtual void begin_write_egl_configs(EGLint const p_num_configs) = 0;
	virtual void write_egl_config(egl_config const &p_egl_config) = 0;
	virtual void end_write_egl_configs() = 0;
	virtual void write_no_egl_configs() = 0;

	virtual void write_glapi_info(
		  EGLenum const p_api
		, char const *p_api_name
		, char const *p_version
		, char const *p_renderer
		, char const *p_extensions
	) = 0;

	virtual ~writer()
	{
	}
};


} // namespace eglinfo end


#endif

