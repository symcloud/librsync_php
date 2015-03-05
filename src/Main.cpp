#include <stdlib.h>
#include <stdio.h>
#include <phpcpp.h>

#include "Rsync.hpp"

extern "C" {
PHPCPP_EXPORT void *get_module() {
    static Php::Extension extension("librsync_php", "0.1");

    /**
     * rs_result rs_sig_file (FILE *old_file, FILE *sig_file, size_t block_len, size_t strong_len, rs_stats_t *)
     */
    extension.add("rs_sig_file", php_sig_file, {
            Php::ByVal("old_file", Php::Type::String),
            Php::ByVal("sig_file", Php::Type::String)
            /* FIXME
            Php::ByVal("block_len", Php::Type::Numeric),
            Php::ByVal("strong_len", Php::Type::Numeric)
            */
    });

    /**
     * rs_result rs_loadsig_file (FILE *sig_file, rs_signature_t **, rs_stats_t *)
     * rs_result rs_delta_file (rs_signature_t *, FILE *new_file, FILE *delta_file, rs_stats_t *)
     */
    extension.add("rs_delta_file", php_delta_file, {
            Php::ByVal("sig_file", Php::Type::String),
            Php::ByVal("new_file", Php::Type::String),
            Php::ByVal("delta_file", Php::Type::String)
    });

    /**
     * rs_result rs_patch_file (FILE *basis_file, FILE *delta_file, FILE *new_file, rs_stats_t *)
     */
    extension.add("rs_patch_file", php_patch_file, {
            Php::ByVal("basis_file", Php::Type::String),
            Php::ByVal("delta_file", Php::Type::String),
            Php::ByVal("new_file", Php::Type::String)
    });

    return extension;
}
}
