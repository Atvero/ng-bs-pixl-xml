let xml = "<test>TEST</test>";
let options = { "forceArrays": true, "preserveAttributes": true };

let res = PixlXml.parse(xml, ~forceArrays=true, ~preserveAttributes=true);

Js.log(res);
Js.log(PixlXml.stringify(res, ~root="root"))

