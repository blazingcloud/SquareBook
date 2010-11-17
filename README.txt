Creating Square

Application Setup:

This application uses the LLVM 1.6 compiler available in Xcode 3.2.5 and later using the 4.2 iOS SDK

You will also need to Install these required frameworks in addition to the defaults:
QuartzCore
OpenGLES
CoreText
MediaPlayer
AVFoundation
CoreData (optional)

Update your Info.plist with these configurations:

Supported interface orientations
- Landscape (left home button)
- Landscape (right home button)

Status bar is initially hidden
true

Integrate Glimmer into Squares Xcode project:

-Copy all files from the /Classes folder into your xcode project except for the GMAppDelegate
-Copy over the "Glimmer-Animation.plist". This file will the template for your book.
-Finally copy "GMPageViewController.xib" into your project

Glimmer uses png images, mov videos and aiff audio files

First add this line to your app delegate header file:

IBOutlet GMPageViewController *pageViewController;

And add this to your delegate application didFinishLaunchingWithOptions method in the implementation file:

[window addSubview:pageViewController.view];
[window makeKeyAndVisible];
window.autoresizesSubviews = YES;

Now open the MainWindow.xib file and add a view controller to the palette. In the identity inspector give the view controller class "GMPageViewController"
Then select the app delegate and open the connection inspector and hook up the pageViewController reference to the view controller reference you just created. Save and quit interface builder.


Naming convention:

-- Animation format --
pagename_actionObject

-- Book pages --
Page Name: page1

Note:
The cover page is a special case and must be called cover_default.png

-- Page1 objects --
square1
square2

-- Default view (the view that is initially loaded) --
page1_default.png

-- Masks --
These images are used to detect whether a pixel has alpha or not. 
This allows us to know when an object is touched. They should be 
the full size of the screen [1024px x 768px]

page1_tapSquare1.png
page1_tapSquare2.png

-- Tap --
page1_tapSquare1.mov
page1_tapSquare2.mov

-- Tilt --
page1_tiltRight.mov
page1_tiltLeft.mov

-- Audio --
page1.aiff


-- Text --

Page text is defined in a dictionary called "words"
text: page text
The text box is [600px x 600px] 

x: x location of the text box

y: y location of the text box

cues: An array of times in seconds that indicates when the words should be highlighted on the screen as the audio is playing
By default words highlight in the color red
Audacity is a great tool for linux/windows/mac (http://audacity.sourceforge.net/download/). It generates a text file with cues and labels.

Note:
By default text highlighting and audio is turned off. If you would like to enable it go to GMPageViewController loadPgae method and uncomment the line:
// 	[textView play];


Sample plist file:

<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<array>
	<dict>
		<key>name</key>
		<string>cover</string>
	</dict>
	<dict>
		<key>name</key>
		<string>page 1</string>
		<key>words</key>
		<dict>
			<key>text</key>
			<string>Once upon a time there was a square who learned how to stand on his head.</string>
			<key>y</key>
			<integer>10</integer>
			<key>x</key>
			<integer>10</integer>
			<key>cues</key>
			<array>
				<string>1.747302</string>
				<string>2.227664</string>
				<string>2.503401</string>
				<string>2.652880</string>
				<string>2.943129</string>
				<string>3.117279</string>
				<string>3.320454</string>
				<string>3.374150</string>
				<string>4.481451</string>
				<string>4.643991</string>
				<string>5.154830</string>
				<string>5.244807</string>
				<string>5.340590</string>
				<string>5.886259</string>
				<string>6.060408</string>
				<string>6.280998</string>
			</array>
		</dict>
		<key>tap</key>
		<array>
			<string>square</string>
		</array>
	</dict>
	<dict>
		<key>name</key>
		<string>page 2</string>
		<key>words</key>
		<dict>
			<key>text</key>
			<string>And all of his friends jumped up and down and said &quot;Horray!&quot;</string>
			<key>x</key>
			<integer>10</integer>
			<key>y</key>
			<integer>10</integer>
			<key>cues</key>
			<array>
				<string>1.617111</string>
				<string>1.914132</string>
				<string>2.453169</string>
				<string>2.640182</string>
				<string>2.986706</string>
				<string>3.822763</string>
				<string>4.141785</string>
				<string>4.339799</string>
				<string>4.565315</string>
				<string>4.939340</string>
				<string>5.208859</string>
				<string>5.890906</string>
				<string>5.890906</string>
			</array>
		</dict>
		<key>tap</key>
		<array>
			<string>friends</string>
		</array>
	</dict>
</array>
</plist>


Remembering Page location:

If you would like to remember where the last page location was you will need to setup your book with <CoreData>

Add the framework to your project.
Create a model in core data that has an attribute called "currentPage"
currentPage is an Integer 16 type with a default of zero

In your applicationDidBecomeActive delegate method retrieve your model instance or create it if nothing returns. Set the current page on your pageViewController and then call the pageViewController buildUp method.

[pageViewController setCurrentPage:[[configuration currentPage] intValue]];
[pageViewController buildUp];  

In applicationDidEnterBackground you will need to store the current page and tear down the current view. 

[configuration setCurrentPage:[NSNumber numberWithInt:[pageViewController currentPage]]];
[pageViewController tearDown];

This will effectively restart the page when the user comes back to the application.

If you setup your book by selecting the core data checkbox when you created your project all the other pieces should be in place. The configuration will get saved if the application ever terminates. For further information on setting your book up to use core data check out the SquareBookAppDelegate file in the Classes/ folder.
 



