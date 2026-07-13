
add_library(mw_plugin SHARED plugin.c)

set(T_PROJECT_NAME mw_plugin)
if (US_REMOTE_HOST)
	foreach(T_REMOTE_HOST ${US_REMOTE_HOST})
		message(${T_REMOTE_HOST})
		add_custom_command(TARGET ${T_PROJECT_NAME} POST_BUILD COMMAND scp -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null $<TARGET_FILE:${T_PROJECT_NAME}> root@${T_REMOTE_HOST}:/tmp/)
	endforeach()
endif()