let handleOptBool = optBool => optBool
  |> Js.Option.map((. bool) => bool ? true : false)
  |> Js.Nullable.fromOption;

type parseOptions = {. 
  "forceArrays": Js.Nullable.t(bool),
  "preserveAttributes": Js.Nullable.t(bool),
  "lowerCase": Js.Nullable.t(bool),
  "preserveDocumentNode": Js.Nullable.t(bool),
  "preserveWhitespace": Js.Nullable.t(bool),
};

[@bs.module "pixl-xml"] external internal_parse : (string, parseOptions) => _ = "parse";
let parse = ( ~forceArrays=?, ~preserveAttributes=?, ~lowerCase=?, ~preserveDocumentNode=?, ~preserveWhitespace=?, xml:string) => {
  internal_parse(xml, {
    "forceArrays": forceArrays |> handleOptBool,
    "preserveAttributes": preserveAttributes |> handleOptBool,
    "lowerCase": lowerCase |> handleOptBool,
    "preserveDocumentNode": preserveDocumentNode |> handleOptBool,
    "preserveWhitespace": preserveWhitespace |> handleOptBool
  });
};

type xml;
[@bs.module "pixl-xml"] external internal_stringify : ( xml, Js.Nullable.t(Js.String.t) ) => string = "stringify";
let stringify = (~root=?, doc:_) => {
  internal_stringify(doc, root |> Js.Nullable.fromOption);
};