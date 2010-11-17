Creating Square

Application Setup:

This application uses the LLVM 1.6 compiler available in Xcode 3.2.5 and later

You will also need to Install these required frameworks in addition to the defaults:
QuartzCore
OpenGLES
CoreText
MediaPlayer
AVFoundation

Update your Info.plist with these configurations:

Supported interface orientations
- Landscape (left home button)
- Landscape (right home button)

Status bar is initially hidden
true

Integrate Glimmer into Squares Xcode project:

-Copy all files from the /Classes folder into your xcode project except for the GMAppDelegate
-Copy over the "Glimmer-Animation.plist". This file will the template for your book.
-FInally copy "GMPageViewController.xib" into your project

Glimmer uses png images and mov

First add this line to your app delegate header file:

IBOutlet UIViewController *pageViewController;

And add this to your delegate implementation file:

[window addSubview:pageViewController.view];
[window makeKeyAndVisible];
window.autoresizesSubviews = YES;

Now open the MainWindow.xib file and add a view controller to the palette. In the identity inspector give the view controller class "GMPageViewController"
Then select the app delegate and open the connection inspector and hook up the pageViewController reference to the view controller reference you just created. Save and quit interface builder.


Naming convention:

Animation format-
pagename_actionObject

Book pages-
Page Name: page1

Page1 objects-
square1
square2

Default view (the view that is initially loaded)-
page1_default.png

Masks- 
These images are used to detect whether a pixel has alpha or not. 
This allows us to know when an object is touched. They should be 
the full size of the screen [1024pxx768px]

page1_tapSquare1.png
page1_tapSquare2.png

Tap-
page1_tapSquare1.mov
page1_tapSquare2.mov

Tilt-
page1_tiltRight.mov
page1_tiltLeft.mov

Audio-
page1.aiff

Cover Page:

The cover page is a special case and must be called cover_default.png







 



