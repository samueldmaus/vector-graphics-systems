all:
	for d in UnitTest; \
	do \
		$(MAKE) -j --directory=$$d all; \
	done

clean:
	$(MAKE) -j -C UnitTest clean