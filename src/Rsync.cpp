#include <phpcpp.h>
#include <stdlib.h>
#include <stdio.h>
#include "Rsync.hpp"

extern "C" {
#include <librsync.h>
}

/**
 * rs_result rs_sig_file (FILE *old_file, FILE *sig_file, size_t block_len, size_t strong_len, rs_stats_t *)
 */
void php_sig_file(Php::Parameters & params) {
    int32_t block_len = 1;
    int32_t strong_len = 2;

    /* TODO
    if (params[2] != nullptr) {
        block_len = params[2];
    }

    if (params[3] != nullptr) {
        strong_len = params[3];
    }
    */

    FILE *old_file;
    old_file = fopen(params[0], "r");

    FILE *sig_file;
    sig_file = fopen(params[1], "w+");

    rs_result res = rs_sig_file(old_file, sig_file, block_len, strong_len, NULL);

    fclose(old_file);
    fclose(sig_file);

    if (res != 0) {
        throw Php::Exception(rs_strerror(res), res);
    }
}

/**
 * rs_result rs_loadsig_file (FILE *sig_file, rs_signature_t **, rs_stats_t *)
 * rs_result rs_delta_file (rs_signature_t *, FILE *new_file, FILE *delta_file, rs_stats_t *)
*/
void php_delta_file(Php::Parameters & params) {
    rs_signature_t *signature;
    rs_result res;

    FILE *sig_file;
    sig_file = fopen(params[0], "r");

    res = rs_loadsig_file(sig_file, &signature, NULL);

    if (res != 0) {
        fclose(sig_file);
        throw Php::Exception(rs_strerror(res), res);
    }

    FILE *new_file;
    new_file = fopen(params[1], "r");

    FILE *delta_file;
    delta_file = fopen(params[2], "w+");

    res = rs_delta_file(signature, new_file, delta_file, NULL);

    fclose(new_file);
    fclose(sig_file);
    fclose(delta_file);

    if (res != 0) {
        throw Php::Exception(rs_strerror(res), res);
    }
}

/**
 * rs_result rs_patch_file (FILE *basis_file, FILE *delta_file, FILE *new_file, rs_stats_t *)
 */
void php_patch_file(Php::Parameters & params) {
    FILE *basis_file;
    basis_file = fopen(params[0], "r");

    FILE *delta_file;
    delta_file = fopen(params[1], "r");

    FILE *new_file;
    new_file = fopen(params[2], "w+");

    rs_result res = rs_patch_file(basis_file, delta_file, new_file, NULL);

    fclose(basis_file);
    fclose(new_file);
    fclose(delta_file);

    if (res != 0) {
        throw Php::Exception(rs_strerror(res), res);
    }
}
