#include <strings.h>

size_t
strlcat(char * restrict dst, const char * restrict src, size_t maxlen) {
	    const size_t srclen = strlen(src);
	        const size_t dstlen = strnlen(dst, maxlen);
		    if (dstlen == maxlen) return maxlen+srclen;
		        if (srclen < maxlen-dstlen) {
				        memcpy(dst+dstlen, src, srclen+1);
					    } else {
						            memcpy(dst+dstlen, src, maxlen-1);
							            dst[dstlen+maxlen-1] = '\0';
								        }
			    return dstlen + srclen;
}
