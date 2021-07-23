all:
	for d in VectorGraphics; \
	do \
		$(MAKE) -j --directory=$$d all; \
	done

clean:
	$(MAKE) -j -C VectorGraphics clean