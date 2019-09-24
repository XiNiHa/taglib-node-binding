function(AddCommonConfig addonName)
    target_compile_definitions(${addonName} PRIVATE
        SPDLOG_COMPILED_LIB
    )
    target_compile_features(${addonName} PRIVATE
        cxx_inheriting_constructors
        cxx_lambdas
        cxx_auto_type
        cxx_variadic_templates
        cxx_variable_templates
    )
    if (WIN32) 
        target_compile_definitions(${addonName} PRIVATE
            ENUM_BITFIELDS_NOT_SUPPORTED
        )
    endif()
endfunction(AddCommonConfig addonName)