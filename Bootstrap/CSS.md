#CSS

## Position Layout
- static:
    * default
    * not affected by top, bottom, left, right
    * No special positioning, always positioned according to the flow of the page
- relative:
    * behaves same way as static, unless some extra properties are added
    * left, right, top, bottom are used to drift it away from it's normal position
    * Other contents will not move in order to fill the gaps created
- fixed: 
    * positioned relative to the viewport. Even if page is scrolled, it don't change it's position
    * top, right, bottom, left are used to position it.
- absolute:
    * Is positioned relative to the nearest *positioned* ancestor

## Font-Size
Relative lengths:
- rem: Relative to the font-size of the root element(for most browser root element is *html* tag: 16px) 
- em: Relative to font-size of the element
- vw(vh): Relative to 1% of the width(height) of the viewport
- vmin(vmax): Relative to 1% of the viewport's smaller(bigger) dimension

Absoulute Lengths:
- px: 1/96 inch. (Also equals 1 pixel for low dpi devices) 

## Viewport:
- Viewport controls how a page is displayed on mobile devices
- Without viewport, mobile device will render the page at a typical desktop screen width, scaled to fit the screen
- Pages optimized for mobile devices should include a meta viewport in the head:
```html
<meta name=viewport content="width=device-width, initial-scale=1">
```
- With respect to the font sizes, viewport refers to width of browser window.

## Display property:
- The default for most element is usually block or inline
- display:none => renders the page as if element does not exist 
- visiblity:hide => will hide the element but space will not be filled

## Height-Width:
- height, width properties do not include padding, borders or margins

## Html5 Datat Attribute:
- A custom attribute of any element that stores data
- data-[only alphabetical word in lowercase is allowed]
