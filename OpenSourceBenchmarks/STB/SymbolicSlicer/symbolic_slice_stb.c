static float stb__perlin_lerp(float a, float b, float t)
{
   return a + (b-a) * t;
static int stb__perlin_fastfloor(float a)
{
    int ai = (int) a; /*STB_SP6*/
    return (a < ai) ? ai-1 : ai; /*STB_SP6*/
static float stb__perlin_grad(int grad_idx, float x, float y, float z)
{
   static float basis[12][4] = /*STB_SP6*/
      {  1, 1, 0 },
   float *grad = basis[grad_idx]; /*STB_SP6*/
   return grad[0]*x + grad[1]*y + grad[2]*z; /*STB_SP6*/
float stb_perlin_noise3_wrap_nonpow2(float x, float y, float z, int x_wrap, int y_wrap, int z_wrap, unsigned char seed)
{
   float u,v,w;
   float n000,n001,n010,n011,n100,n101,n110,n111;
   float n00,n01,n10,n11;
   float n0,n1;
   int px;
   int py;
   int pz;
   int x_wrap2;
   int y_wrap2;
   int z_wrap2;
   int x0, x1;
   int y0, y1;
   int z0, z1;
   int r0,r1, r00,r01,r10,r11;
   px = stb__perlin_fastfloor(x); /*STB_SP6*/
   py = stb__perlin_fastfloor(y); /*STB_SP6*/
   pz = stb__perlin_fastfloor(z); /*STB_SP6*/
   x_wrap2 = (x_wrap ? x_wrap : 256); /*STB_SP6*/
   y_wrap2 = (y_wrap ? y_wrap : 256); /*STB_SP6*/
   z_wrap2 = (z_wrap ? z_wrap : 256); /*STB_SP6*/
   x0 = px % x_wrap2; /*STB_SP6*/
   y0 = py % y_wrap2; /*STB_SP6*/
   z0 = pz % z_wrap2; /*STB_SP6*/
   if (x0 < 0) x0 += x_wrap2; /*STB_SP6*/
   if (y0 < 0) y0 += y_wrap2; /*STB_SP6*/
   if (z0 < 0) z0 += z_wrap2; /*STB_SP6*/
   x1 = (x0+1) % x_wrap2;
   y1 = (y0+1) % y_wrap2;
   z1 = (z0+1) % z_wrap2;
   x -= px; u = stb__perlin_ease(x); /*STB_SP6*/
   y -= py; v = stb__perlin_ease(y); /*STB_SP6*/
   z -= pz; w = stb__perlin_ease(z); /*STB_SP6*/
   r0 = stb__perlin_randtab[x0]; /*STB_SP6*/
   r0 = stb__perlin_randtab[r0+seed]; /*STB_SP6*/
   r1 = stb__perlin_randtab[x1];
   r1 = stb__perlin_randtab[r1+seed];
   r00 = stb__perlin_randtab[r0+y0]; /*STB_SP6*/
   r01 = stb__perlin_randtab[r0+y1];
   r10 = stb__perlin_randtab[r1+y0];
   r11 = stb__perlin_randtab[r1+y1];
   n000 = stb__perlin_grad(stb__perlin_randtab_grad_idx[r00+z0], x  , y  , z   ); /*STB_SP6*/
   n001 = stb__perlin_grad(stb__perlin_randtab_grad_idx[r00+z1], x  , y  , z-1 );
   n010 = stb__perlin_grad(stb__perlin_randtab_grad_idx[r01+z0], x  , y-1, z   );
   n011 = stb__perlin_grad(stb__perlin_randtab_grad_idx[r01+z1], x  , y-1, z-1 );
   n100 = stb__perlin_grad(stb__perlin_randtab_grad_idx[r10+z0], x-1, y  , z   );
   n101 = stb__perlin_grad(stb__perlin_randtab_grad_idx[r10+z1], x-1, y  , z-1 );
   n110 = stb__perlin_grad(stb__perlin_randtab_grad_idx[r11+z0], x-1, y-1, z   );
   n111 = stb__perlin_grad(stb__perlin_randtab_grad_idx[r11+z1], x-1, y-1, z-1 );
   n00 = stb__perlin_lerp(n000,n001,w); /*STB_SP6*/
