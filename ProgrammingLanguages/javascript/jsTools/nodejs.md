# `node.js` premier:
Node.js is a cross-platform Javascript run-time environment that executes Javascript code outside browser. "Javascript everywhere". Let's you write command line tools, backend language etc. (Node.js does not refer to a particular file, it's just the name of the product)

# `npm` premier:
- Node package manager. npm is used to manage packages for node.js. It also consist of a database of public and private node packages called npm registry
- npm installing globally vs locally: 
  * globally: This install modules in `/usr/local/lib/node_modules` and binaries inside `/usr/local/bin/`. Also installs man pages.
  * locally: Install packages in cwd. Modules inside `./node_modules` and executables inside `./node_modules/.bin/`
  * Only use global when you really need them. Rule of thumb: If you want to use a package inside a  js program like `require('whatever')`, then install it locally. If you want to use it from cli, install it globally.
  * Some packages have program as well as command line access like "Express". Best is to install it at both places.

# Basic of `node.js` project:
  * Any project using node.js should have a package.json file. It includes:
    1. Packages and applications the project depends upon
    2. Metadata: Project's name, author, description etc.
    3. Dependencies: One never ships dependencies with the package. Users can install them via `npm install` command. They are of two types as below. Key is name and value is allowed version.
      - `dependencies`
      - `devdependencies`
  * `npm init`:
    1. Will allow you to provide name, initial version, description, entry point, test command, git repository, 
    2. Based on above, package.json file will be created in cwd.
  * `npm install`:
    1. `npm install`: install all packages in dependencies key.
    2. `npm install <package>`: install a particular package.
    3. `npm install <package> --save`: `npm install` does not automatically add package as dependency in package.json file. Use `--save` to do so. Use `--save-dev` to install package as developer dependency.
    4. `npm install --global`: As discussed above, use this install packages globally as needed.