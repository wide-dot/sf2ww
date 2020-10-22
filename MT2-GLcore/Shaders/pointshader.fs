#version 330

precision lowp float;

flat in int tileIdentifier;
flat in int tileAttribute;

uniform sampler2D u_image;
uniform sampler2D u_palette;

uniform int tileId;
uniform int tileSize;
uniform int tileByteSize = 0x80;

uniform int atlasWidth;
uniform int atlasHeight;

/* this is 8 bytes for SCR1, SCR2 and sprites, and 16 bytes for SCR3 (SCR1 seems to waste a byte for each group of 8 pixels) */
uniform int rowByteStride = 8;

out vec4 fragColor;

const int bitsPerByte = 8;
const int bitsPerNibble = 4;

void main() {
//    fragColor = vec4(gl_PointCoord, 0.0, 1.0);
//    return;
    // scale the point coord to tile dimensions
    vec2 pixelFloat = gl_PointCoord * tileSize;
    ivec2 pixel = ivec2(int(pixelFloat.x), int(pixelFloat.y));
    
    int palette = tileAttribute & 0xf;
    int flips = (tileAttribute & 0x60) >> 5;
    
    // we need to get the pixel color index, which requires reading four bytes from
    // the `index` texture
    
    vec2 pixelStride = vec2(1.0 / float(atlasWidth), 1.0 / float(atlasHeight));
    
    //float pixelStride = 1.0 / atlasWidth;
    vec2 halfStride = pixelStride / 2.0;
    
    //float pixelStrideVert = 1.0 / atlasHeight;
        
    int pixelId =
    tileByteSize * tileIdentifier + // byte size of a tile
        (pixel.x / bitsPerByte) * bitsPerNibble + // number of bits per byte, bit per nibble
    rowByteStride * pixel.y; // bytes per row
    
    int xOff = pixelId % atlasWidth;
    int yOff = pixelId / atlasWidth;
    
    int bit = 7 - (pixel.x % 8);
    
    vec2 tileCoord1 = vec2(pixelStride.x * (xOff + 0) + halfStride.x, pixelStride.y * yOff + halfStride.y);
    vec2 tileCoord2 = vec2(pixelStride.x * (xOff + 1) + halfStride.x, pixelStride.y * yOff + halfStride.y);
    vec2 tileCoord4 = vec2(pixelStride.x * (xOff + 2) + halfStride.x, pixelStride.y * yOff + halfStride.y);
    vec2 tileCoord8 = vec2(pixelStride.x * (xOff + 3) + halfStride.x, pixelStride.y * yOff + halfStride.y);

//    int bit1 = (int(texture(u_image, tileCoord1).r) * 255) & (1 << bit);
//    int bit2 = (int(texture(u_image, tileCoord2).r) * 255) & (1 << bit);
//    int bit4 = (int(texture(u_image, tileCoord4).r) * 255) & (1 << bit);
//    int bit8 = (int(texture(u_image, tileCoord8).r) * 255) & (1 << bit);

    int b1 = (int(texture(u_image, tileCoord1).r * 255) & (1 << bit));
    int b2 = (int(texture(u_image, tileCoord2).r * 255) & (1 << bit));
    int b4 = (int(texture(u_image, tileCoord4).r * 255) & (1 << bit));
    int b8 = (int(texture(u_image, tileCoord8).r * 255) & (1 << bit));
    
    int idx =
        (b1 != 0 ? 1 : 0) |
        (b2 != 0 ? 2 : 0) |
        (b4 != 0 ? 4 : 0) |
        (b8 != 0 ? 8 : 0);
    
//    int idx;
//    if (bit8 != 0) idx |= 0x8;
//

    if (idx == 15)
        discard;
    
    //float index = texture(u_image, gl_PointCoord).r; // * 255.0;
    
    
    
    // the CPS palette is packed in ARGB format, so shift it
    vec4 cpsColor = texture(u_palette, vec2(idx / 15.0 , palette / 31.0));
    
    vec3 rawColor = cpsColor.gba;
    vec3 brightness = vec3(cpsColor.r);
    
    fragColor = vec4(rawColor * brightness, 1.0);
    
    
//    fragColor = vec4(idx / 15.0, 0.0, tileCoord1.y * 16.0, 1.0);
}

