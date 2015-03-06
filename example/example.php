<?php
rs_sig_file('test-a.txt', 'test-a.sig');
rs_delta_file('test-a.sig', 'test-b.txt', 'test-a.delta');
rs_patch_file('test-a.txt', 'test-a.delta', 'test-a-new.txt');
