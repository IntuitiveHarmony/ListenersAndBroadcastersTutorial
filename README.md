# Listeners and Broadcasters

This is a tutorial from the JUCE website
https://docs.juce.com/master/tutorial_listeners_and_broadcasters.html

Through this we are going to learn how to use a button to print the current in a label window

## Broadcasters

- In JUCE, buttons, sliders, and many other types of controls that may need to inform other objects about a change in their state are a type of `broadcaster` object

## Listeners

- In order to respond to changes in a `broadcaster` object, other classes need to be a `listener` for that specific type of `broadcaster`

- `Listners` are nessted within `broadcasters` *ie* `Button::Listner`

- Will have a [pure vital function](https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/) that will be used as a call back function in order to broadcast its change. 