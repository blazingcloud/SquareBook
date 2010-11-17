{\rtf1\ansi\ansicpg1252\cocoartf1038\cocoasubrtf350
{\fonttbl\f0\fswiss\fcharset0 Helvetica;\f1\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red170\green13\blue145;\red92\green38\blue153;\red63\green110\blue116;
\red46\green13\blue110;}
\margl1440\margr1440\vieww12400\viewh15340\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\ql\qnatural\pardirnatural

\f0\b\fs32 \cf0 Creating Square
\b0\fs24 \
\

\b\fs28 Application Setup:
\fs24 \

\b0 \
This application uses the LLVM 1.6 compiler available in Xcode 3.2.5 and later\
\
You will also need to Install these required frameworks in addition to the defaults:\
QuartzCore\
OpenGLES\
CoreText\
MediaPlayer\
AVFoundation\
\

\b\fs28 Update your Info.plist with these configurations:
\fs24 \

\b0 \
Supported interface orientations\
- Landscape (left home button)\
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\ql\qnatural\pardirnatural
\cf0 - Landscape (right home button)\
\
Status bar is initially hidden\
true\
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\ql\qnatural\pardirnatural
\cf0 \

\b\fs28 Integrate Glimmer into Squares Xcode project:
\b0\fs24 \
\
-Copy all files from the /Classes folder into your xcode project except for the GMAppDelegate\
-Copy over the "Glimmer-Animation.plist". This file will the template for your book.\
-FInally copy "GMPageViewController.xib" into your project\
\
Glimmer uses png images and mov\
\
First add this line to your app delegate header file:\
\
\pard\tx640\pardeftab640\ql\qnatural\pardirnatural

\f1\fs26 \cf2 \CocoaLigature0 IBOutlet\cf0  \cf3 UIViewController\cf0  *\cf4 pageViewController\cf0 ;\
\
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\ql\qnatural\pardirnatural

\f0\fs24 \cf0 \CocoaLigature1 And add this to your delegate implementation file:\

\f1\fs26 \CocoaLigature0 \
\pard\tx640\pardeftab640\ql\qnatural\pardirnatural
\cf0 [\cf4 window\cf0  \cf5 addSubview\cf0 :\cf4 pageViewController\cf0 .\cf5 view\cf0 ];\
[\cf4 window\cf0  \cf5 makeKeyAndVisible\cf0 ];\
\cf4 window\cf0 .\cf3 autoresizesSubviews\cf0  = \cf2 YES\cf0 ;
\f0\fs24 \CocoaLigature1 \
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\ql\qnatural\pardirnatural
\cf0 \
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\ql\qnatural\pardirnatural
\cf0 Now open the MainWindow.xib file and add a view controller to the palette. In the identity inspector give the view controller class "GMPageViewController"\
Then select the app delegate and open the connection inspector and hook up the pageViewController reference to the view controller reference you just created. Save and quit interface builder.\
\
\

\b\fs28 Naming convention:
\b0\fs24 \
\

\fs26 Animation format-
\fs24 \
pagename_actionObject\
\

\fs26 Book pages-
\fs24 \
Page Name: page1\
\

\fs26 Page1 objects-
\fs24 \
square1\
square2\
\

\fs26 Default view (the view that is initially loaded)-
\fs24 \
page1_default.png\
\

\fs26 Masks- 
\fs24 \
These images are used to detect whether a pixel has alpha or not. \
This allows us to know when an object is touched. They should be \
the full size of the screen [1024pxx768px]\
\
page1_tapSquare1.png\
page1_tapSquare2.png\
\

\fs26 Tap-
\fs24 \
page1_tapSquare1.mov\
page1_tapSquare2.mov\
\

\fs26 Tilt-
\fs24 \
page1_tiltRight.mov\
page1_tiltLeft.mov\
\

\fs26 Audio-
\fs24 \
page1.aiff\
\

\b\fs28 Cover Page:
\b0\fs24 \
\
The cover page is a special case and must be called cover_default.png\
\
\
\
\
\
\
\
 \
\
\
\
}