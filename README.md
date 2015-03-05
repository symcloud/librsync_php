# PHP-Bindings for librsync

This php extension provides a binding to the [librsync](https://github.com/librsync/librsync) C-library. This library
is a open-source implementation of the rsync [remote-delta algorithm](https://rsync.samba.org/tech_report/).

This algorithm is using a rolling check-sum and a md4 check-sum for blocks of the file to generate a signature file.
The signature file is used to generate a diff from the file on the remote site. This diff can be used on the local
site to patch the file.

## Install

__Requirements:__

* [PHP-CPP](http://www.php-cpp.com/)
* PHP5
* librsync
* make
* g++

__Steps:__

After clone edit `Makefile` to match your PHP installation (especially INI_DIR).

```bash
git clone git@github.com:symcloud/librsync_php.git
cd librsync_php
make
sudo make install
```

## Example

```php
rs_sig_file('test/test-a.txt', 'test/test-a.sig');
rs_delta_file('test/test-a.sig', 'test/test-b.txt', 'test/test-a.delta');
rs_patch_file('test/test-a.txt', 'test/test-a.delta', 'test/test-a-new.txt');
```
