# Listeners and Broadcasters

This follows a tutorial from the JUCE website
https://docs.juce.com/master/tutorial_listeners_and_broadcasters.html

- Take a look at my [code](https://github.com/IntuitiveHarmony/ListenersAndBroadcastersTutorial/blob/master/Source/ListenersAndBroadcastersTutorial_01.h) if you'd like. 

- Everything I added into the source code is commented on `// ~~ like this ~~`

![Button Demo](/images/Demo.gif "Expanded Version")

<br />
<hr />

## What I learned

I am more comfortable with `broadcasters` and `listeners`.  I expaneded on the orginal tutorial and added a check the date button.  Since the author of JUCE is from England he uses a different spelling for `colour` and `centred`.  I ran into a slight issue when I was trying to use `centered` for the labels.  It took me a little bit to wrap my head around what was going on!

### Broadcasters

- In JUCE, buttons, sliders, and many other types of controls that may need to inform other objects about a change in their state are a type of `broadcaster` object

### Listeners

- In order to respond to changes in a `broadcaster` object, other classes need to be a `listener` for that specific type of `broadcaster`

- `Listners` are nessted within `broadcasters` *ie* `Button::Listner`

- Will have a [pure vital function](https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/) that will be used as a call back function in order to broadcast its change. 

- Removing listeners appropriately is important if you set up more complex broadcaster-listener systems.

