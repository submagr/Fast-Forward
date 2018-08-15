I was developing a small webapp, which I earlier started as a small project. The hosting was static and I managed authentication using firebase authentication package. As the webapp expanded (which I didn't plan earlier), I started facing following problems:
1. I have to duplicate my entire HTML code (for navigation/authentication bar atleast).
2. I have to duplicate my entire authentication javascript every time. Suppose I have page A and page B. Both of these require an approval from authenticator to start their work. Many times, the work of both the pages are similar, but sometimes the work is different. Suppose the work of page B is entirely different with a few functionalities I need to borrow from page A. For this, there was no easy way to "import" the functions.

For this, I google how to write "modular", "importable" code in javascript that run on browsers. The functionalities are available via "import" in ECMA6 javascript, but until this date (July 2018), it is not supported by most browsers. There are several workarounds or hacks available.
1. Transportation tools:
2. Use ES6 Modules and Transpile in earlier compatible versions
3. AJAX loading:
4. jQuery loading:
5. Dynamic script loading

Reference: [how-do-i-include-a-javascript-file-in-another-javascript-file](https://stackoverflow.com/questions/950087/how-do-i-include-a-javascript-file-in-another-javascript-file)


The method I am going ahead with: I am going ahead with is Dynamic script loading. It seems simple. Morevoer, my requirement is pretty small here: split up the code to avoid duplicacy. I am not concerned right now with efficiency and scalability. Moreover, in this way, when I will use more advanced tools like webpack, babel etc.I will already know what are their exact benefits.