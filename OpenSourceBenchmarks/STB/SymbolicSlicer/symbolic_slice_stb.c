92    return a + (b-a) * t;
    
97     int ai = (int) a; /*STB_SP6*/
98     return (a < ai) ? ai-1 : ai; /*STB_SP6*/

103    static float basis[12][4] = /*STB_SP6*/
105       {  1, 1, 0 },
119    float *grad = basis[grad_idx]; /*STB_SP6*/
120    return grad[0]*x + grad[1]*y + grad[2]*z; /*STB_SP6*/

252    px = stb__perlin_fastfloor(x); /*STB_SP6*/
253    py = stb__perlin_fastfloor(y); /*STB_SP6*/
254    pz = stb__perlin_fastfloor(z); /*STB_SP6*/
255    x_wrap2 = (x_wrap ? x_wrap : 256); /*STB_SP6*/
256    y_wrap2 = (y_wrap ? y_wrap : 256); /*STB_SP6*/
257    z_wrap2 = (z_wrap ? z_wrap : 256); /*STB_SP6*/
258    x0 = px % x_wrap2; /*STB_SP6*/
259    y0 = py % y_wrap2; /*STB_SP6*/
260    z0 = pz % z_wrap2; /*STB_SP6*/
262    if (x0 < 0) x0 += x_wrap2; /*STB_SP6*/
263    if (y0 < 0) y0 += y_wrap2; /*STB_SP6*/
264    if (z0 < 0) z0 += z_wrap2; /*STB_SP6*/
265    x1 = (x0+1) % x_wrap2;
266    y1 = (y0+1) % y_wrap2;
267    z1 = (z0+1) % z_wrap2;
271    x -= px; u = stb__perlin_ease(x); /*STB_SP6*/
272    y -= py; v = stb__perlin_ease(y); /*STB_SP6*/
273    z -= pz; w = stb__perlin_ease(z); /*STB_SP6*/
275    r0 = stb__perlin_randtab[x0]; /*STB_SP6*/
276    r0 = stb__perlin_randtab[r0+seed]; /*STB_SP6*/
277    r1 = stb__perlin_randtab[x1];
278    r1 = stb__perlin_randtab[r1+seed];
280    r00 = stb__perlin_randtab[r0+y0]; /*STB_SP6*/
281    r01 = stb__perlin_randtab[r0+y1];
282    r10 = stb__perlin_randtab[r1+y0];
283    r11 = stb__perlin_randtab[r1+y1];
285    n000 = stb__perlin_grad(stb__perlin_randtab_grad_idx[r00+z0], x  , y  , z   ); /*STB_SP6*/
286    n001 = stb__perlin_grad(stb__perlin_randtab_grad_idx[r00+z1], x  , y  , z-1 );
287    n010 = stb__perlin_grad(stb__perlin_randtab_grad_idx[r01+z0], x  , y-1, z   );
288    n011 = stb__perlin_grad(stb__perlin_randtab_grad_idx[r01+z1], x  , y-1, z-1 );
289    n100 = stb__perlin_grad(stb__perlin_randtab_grad_idx[r10+z0], x-1, y  , z   );
290    n101 = stb__perlin_grad(stb__perlin_randtab_grad_idx[r10+z1], x-1, y  , z-1 );
291    n110 = stb__perlin_grad(stb__perlin_randtab_grad_idx[r11+z0], x-1, y-1, z   );
292    n111 = stb__perlin_grad(stb__perlin_randtab_grad_idx[r11+z1], x-1, y-1, z-1 );
294    n00 = stb__perlin_lerp(n000,n001,w); /*STB_SP6*/
