#include <stdlib.h>
#include <stdio.h>
#include <phpcpp.h>
#include <sys/types.h>

extern "C" {
#include <librsync.h>
}

Php::Value myFunction(Php::Parameters & params) {
    FILE *fpa;
    fpa = fopen(params[0], "r");

    FILE *fps;
    fps = fopen(params[1], "w+");

    rs_result res = rs_sig_file(fpa, fps, 1, 2, NULL);

    fclose(fpa);
    fclose(fps);

    return res;
}

extern "C" {
PHPCPP_EXPORT void *get_module() {
    static Php::Extension extension("librsync_php", "0.1");
    extension.add("rs_sig_file", myFunction, {
            Php::ByVal("filename", Php::Type::String),
            Php::ByVal("sigfile", Php::Type::String)
    });
    return extension;
}
}
