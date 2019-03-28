# WARNING

I was going to patch this version to add support for bs-platform ^5.0.0, but it's already been done. The package on npm is not up to date with the source repository. 

## Bucklescript bindings to pixl-xml

Bindings for [pixl-xml](https://github.com/jhuckaby/pixl-xml) XML parser.

### Getting started

```
npm install bs-pixl-xml --save
```

or 

```
yarn add bs-pixl-xml
```

Add `"bs-pixl-xml"` to `bs-dependencies` in your project's `bsconfig.json`

### Example

```rs
let result = PixlXml.parse("<test><A>a</A></test>", ~forceArrays=true );
Js.log(result);
```
