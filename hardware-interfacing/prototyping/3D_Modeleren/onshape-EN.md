![picture1](../3D_Modeleren/img/onshape/logo.png) [](logo-id)

# 3D Modelleren[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->

- [Een introductie](#een-introductie)
- [De basis van Fusion 360](#de-basis-van-fusion-360)
- [Gebruik van bestaande modellen](#gebruik-van-bestaande-modellen)
  - [Bekende dimensies](#bekende-dimensies)
  - [Onbekende dimensies](#onbekende-dimensies)
- [bronnen](#bronnen)

---

**v0.1.0 [](version-id)** Start document voor 3D modelleren uitleg en voorbeelden door HU IICT[](author-id).

---

## An introduction

There are many 3D modeling programs you can use to create objects for 3D printing or laser cutting. For this instruction we use On Shape. This software has capabilities for both flat materials and 3D object modeling. We will mainly focus on 3D models, but with this instruction you can just as easily create flat drawings to serve as a basis for a vector file that can be interpreted by a laser program. The difference with many other software tools is that On Shape runs entirely in the browser. 

## The basics of On shape
When you open On Shape you will first see an empty screen with a number of buttons.

![picture1](../3D_Modeleren/img/onshape/startscherm.png)

It is important to save first (red frame). This activates additional options and ensures your timeline is properly stored. In the green frame you see a cube, and from it you can tell how you are viewing your drawing. To start a drawing you always begin with a flat sketch. You can open this by pressing the sketch button (blue frame).
The screen then changes into a grid with an image of the X, Y and Z axes as shown on the cube:

![picture2](../3D_Modeleren/img/onshape/XYZ.png)

Here X is red, Y is green and Z is blue. For your sketch you must select one of these planes to start. Which plane you choose largely depends on what you want to make. For this instruction we will make a simple box with a lid. We want to look at the box from the top and select the plane between green and red. The view now changes and you are in 2D sketch mode:

![picture3](../3D_Modeleren/img/onshape/vartable.png)

We can also see this from the changed toolbar:

![picture4](../3D_Modeleren/img/onshape/vartableformula.png)

We can now immediately start drawing using the buttons under create. However, it is often wise to first think about which dimensions you want. These often have a relationship with each other. For example, the width being twice the length. Or that a hole should always be in the center of a plate regardless of the size of the plate. You can define this by going to the modify menu and clicking change parameters. In the parameter menu you can then create properties that you want to use in your model. You can use fixed values or write formulas:

If we now create a rectangle in the drawing, for example, we can use these properties. 

![picture6](../3D_Modeleren/img/onshape/basebox.png)

The advantage is that with complex models you can quickly adjust the entire model without putting proportions at risk. It really pays off to think about this in advance. You can recognize a user variable by the prefix fx:. When you open the dimension you will see the name of the parameter again. If we would make this 3D, we would only have a block. To create a box we must first define what the walls are. We can create a new user variable or directly create an offset using the offset button. The letters behind the items represent the shortcuts you can use:

![picture7](../3D_Modeleren/img/onshape/offset.png)

If you press offset you get the option to select an object:

and then specify how much. With negative values you go inward, with positive outward:
With this we have created the base for our box and we can start extruding it. To go to the 3D environment you can press finish sketch in the top right corner:

![picture10](../3D_Modeleren/img/onshape/finishsketch.png)

To turn the flat sketch into a 3D object you can click extrude in the create menu or press e.

![picture11](../3D_Modeleren/img/onshape/extrude.png)

Here you can again use the properties we created or add new ones. In this case we will extrude the inside 2mm without using parameters. 

![picture12](../3D_Modeleren/img/onshape/Extrudebase.png)

For this you first need to select the profile and you will also see that a new 3D object will be created. If you now press ok you can rotate in 3D with shift + middle mouse button and see what you have made:

![picture13](../3D_Modeleren/img/onshape/extrude1base.png)

Now we also need to create walls. We still see the sketch line around the object, but it may be automatically turned off after the first extrusion; you can turn it back on on the left side under sketches. To create the walls, select extrude again, select the profile you want to extrude and specify how much. 

![picture14](../3D_Modeleren/img/onshape/sketchbackon.png)

You can again use the user parameters here. You do not need to create new ones. If all sides are connected to another extrusion, Fusion will try to join them together and thus create a single object. We now have a box, but you may also want a lid. We can use the same sketch for this. However, we now extrude from another object:

![picture15](../3D_Modeleren/img/onshape/extrude2.png)

It can be useful to temporarily hide the body on the left so you can see the sketch again. Make sure you set the operation to New Body instead of Join. Optionally you can extrude the middle part downward to create a small edge. 

![picture16](../3D_Modeleren/img/onshape/editside.png)

Each side of the box can also be selected to create sketches. Keep in mind that if you do this and later change the box, it can affect these sketches. You can use these sketches to create, for example, a hole in the model or add text. Both can be made using the extrude command. If you extrude through a body, you can set the operation to Cut, which removes the profile from the body. With the fillet command we can make sharp edges more rounded:

![picture17](../3D_Modeleren/img/onshape/fillet.png)

There are of course many more possibilities. In the sources you will find links to videos that explain examples of usage in more detail. This is only a selection; there is much more available, and if you have specific challenges there is definitely something out there for it. Also take a look at the different options available when creating the 2D sketch and the 3D object. 

## Use of existing models
You usually make a box for an object you want to put inside it, for example a housing for a microcontroller or a sensor. Sometimes you know the dimensions of the object and sometimes you do not. Below are three possible ways to handle this in Fusion.

### Known dimensions
For many objects you use, drawings are already available. As an example, you could create a housing for the Arduino Uno. If we search for Arduino Uno dimensions, we might find a drawing like this:

![picture26](../3D_Modeleren/img/fusion/Picture26.png)
[1]

In the previous chapter it was already described how we can influence the dimensions of the box using user parameters. We can copy the dimensions from the drawing and use them, for example, to create holes for USB ports and similar features. The locations of mounting holes are also shown in the drawing. In Fusion we can model standoffs so the model can be screwed in place. The only thing needed is adjusting the sketch. With the dimension (d) command you can specify how far an object should be placed from another object. Of course it is wise to use user parameters for this!

A second option is to import a complete 3D model. For this you can create an account on, for example, GrabCAD or use the import function of On Shape.

## Sources


