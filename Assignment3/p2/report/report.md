## Report


#### Red sphere, highlight on the surface of diffuse object
![alt text](./imgs/red-sphere.png)

There are two lights in this sphere, one is the general light used to create the general color of the sphere and one spotlight.

The highlight in center of the red sphere can be implemented using spotlight, however, since the spot does not have clear edge, we have to smooth the edge using Hermite interpolation. Input of the interpolation is the angle of current vertex, based on the inner and outer angle, we interpolate a value between 0 and 1 and call it spoteffect, value of spoteffect is multiplied with sum of specular and diffuse color just like attenuation value.

The intensity of specular and ambient color in the spotlight is disable (assign 0) because we do not need them here, so the color comes from diffuse color and the interpolation of diffuse color.

The spot light has color white, to avoid passing more color, we use specular color of material (which we do not in this case and assign as white) as diffuse color of the spotlight.

The sphere is placed in the center and we always direct the light toward the center, so we try to change the position of the light to the right to create the shadow on the left.


#### Yellow sphere, little highlight and smooth cutoff angle
![alt text](./imgs/yellow-sphere.png)

There are four lights in this sphere, one is the general light, two spotlight lights to create the blur little highlight and one spotlight to create the big smooth cutoff light.

The fourth light does not have a circle shape on the sphere so we have to change direction and position of the spotlight a lot of time until get a good enough one like int the image above.

We also add 0.003 into the interpolation value of the fourth light to make it more distinct with the background on the sphere. 
