OBJEVENTGFXDIR := graphics/object_events/pics

$(OBJEVENTGFXDIR)/people/brendan/walking.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENTGFXDIR)/people/brendan/running.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENTGFXDIR)/people/may/walking.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENTGFXDIR)/people/may/running.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENTGFXDIR)/people/ruby_sapphire_brendan/walking.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENTGFXDIR)/people/ruby_sapphire_brendan/running.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENTGFXDIR)/people/ruby_sapphire_may/walking.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENTGFXDIR)/people/ruby_sapphire_may/running.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENTGFXDIR)/people/jess_frlg.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 4 -mheight 4
	
$(OBJEVENTGFXDIR)/people/james_frlg.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 4 -mheight 4
	
$(OBJEVENTGFXDIR)/people/samurai_frlg.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 4 -mheight 4
	
# $(OBJEVENTGFXDIR)/people/charmander_frlg.4bpp: %.4bpp: %.png
	# $(GFX) $< $@ -mwidth 4 -mheight 2