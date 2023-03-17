# Listeners and Broadcasters

This follows a tutorial from the JUCE website
https://docs.juce.com/master/tutorial_listeners_and_broadcasters.html

Going through this I hope to learn how to use a button to print the current time in a label window.  Code I wrote into the source code is commented on `// ~~ like this ~~`

![Button Demo](/images/Demo.gif)

## Broadcasters

- In JUCE, buttons, sliders, and many other types of controls that may need to inform other objects about a change in their state are a type of `broadcaster` object

## Listeners

- In order to respond to changes in a `broadcaster` object, other classes need to be a `listener` for that specific type of `broadcaster`

- `Listners` are nessted within `broadcasters` *ie* `Button::Listner`

- Will have a [pure vital function](https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/) that will be used as a call back function in order to broadcast its change. 

- Removing listeners appropriately is important if you set up more complex broadcaster-listener systems.

### What I learned

I am more comfortable with `broadcasters` and `listeners`.  I expaneded on the orginal tutorial and added a check the date button.  