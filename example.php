rs_sig_file('test/test-a.txt', 'test/test-a.sig');
rs_sig_file('test/test-b.txt', 'test/test-b.sig');

rs_delta_file('test/test-a.sig', 'test/test-b.txt', 'test/test-a.delta');
rs_delta_file('test/test-b.sig', 'test/test-a.txt', 'test/test-b.delta');
