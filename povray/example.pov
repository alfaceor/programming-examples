#include "colors.inc"
//#include "shapes.inc"

camera {
  location <0,0,-10>
  look_at <0,0,0>
}

light_source {
  <4, 6, -10>
  White
}


//background { Grey }

sky_sphere {
  pigment {
    gradient y
    color_map  {
      [0 color White ]
      [1 color Blue  ]
    }
  }
}

sphere {
  <0,0,0>, 2
  pigment { Red }
  finish { ambient 0.4 }
}


box {
  <2,0,0>, <3,1,1>
  pigment { Red }
  finish { ambient 0.4 }
}
