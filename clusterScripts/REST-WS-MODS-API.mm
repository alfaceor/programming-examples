<map version="0.7.1">
<node ID="_Freemind_Link_1860040620" TEXT="REST WS">
<font NAME="SansSerif" BOLD="true" SIZE="12"/>
<node ID="_Freemind_Link_395282828" TEXT="Frontend" STYLE="bubble" POSITION="left">
<cloud/>
<node ID="_" COLOR="#ff0000" TEXT="calcGridValue(POST)" FOLDED="true">
<node ID="_Freemind_Link_566031254" TEXT="INPUT">
<node ID="_Freemind_Link_1301450402" TEXT="EndpointID (string)"/>
<node ID="_Freemind_Link_968080200" TEXT="GridID (string)"/>
<node ID="_Freemind_Link_1539791355" TEXT="Image (zip)"/>
</node>
<node ID="_Freemind_Link_227820675" TEXT="OUTPUT">
<node ID="_Freemind_Link_1742784140" TEXT="Response (json)">
<node ID="_Freemind_Link_1011772543" TEXT="Recieved succesfully"/>
<node ID="_Freemind_Link_9550552" TEXT="Reception failure"/>
<node ID="_Freemind_Link_961464691" TEXT="Unknown Endpoint"/>
</node>
</node>
</node>
<node ID="_Freemind_Link_802546433" COLOR="#ff0000" TEXT="getGridValue(GET)" FOLDED="true">
<node ID="_Freemind_Link_572429160" TEXT="INPUT">
<node ID="_Freemind_Link_514266929" TEXT="EndPointID (string)"/>
</node>
<node ID="_Freemind_Link_361157175" TEXT="OUTPUT">
<node ID="_Freemind_Link_723293533" TEXT="GridID(string)"/>
<node ID="_Freemind_Link_1234024528" TEXT="GridValue (number)"/>
</node>
</node>
<node ID="_Freemind_Link_105251947" COLOR="#0033ff" TEXT="analyzeSample (POST)" FOLDED="true">
<node ID="_Freemind_Link_1801655823" TEXT="INPUT">
<node ID="_Freemind_Link_1000452493" TEXT="EndpointID (string)"/>
<node ID="_Freemind_Link_1139699529" TEXT="SampleID (string)"/>
<node ID="_Freemind_Link_1877329900" TEXT="Image (zip)">
<node ID="_Freemind_Link_23437116" TEXT="Metadata">
<node ID="_Freemind_Link_724448352" TEXT="SampleID (string)"/>
<node ID="_Freemind_Link_650252962" TEXT="GridValue (number)"/>
<node ID="_Freemind_Link_1426974784" TEXT="SampleCellNumber (string)"/>
</node>
<node ID="_Freemind_Link_137251849" TEXT="Sample Image"/>
</node>
</node>
<node ID="_Freemind_Link_1223368138" TEXT="OUTPUT">
<node ID="_Freemind_Link_654515029" TEXT="Response (json)" FOLDED="true">
<node ID="_Freemind_Link_1719479815" TEXT="Recieved succesfully"/>
<node ID="_Freemind_Link_865192413" TEXT="Reception failure"/>
<node ID="_Freemind_Link_498792961" TEXT="Unknown Endpoint"/>
</node>
</node>
</node>
<node ID="_Freemind_Link_1799120104" COLOR="#0033ff" TEXT="getResult (GET)" FOLDED="true">
<node ID="_Freemind_Link_649362425" TEXT="INPUT">
<node ID="_Freemind_Link_226044657" TEXT="EndPointID (string)"/>
</node>
<node ID="_Freemind_Link_131426446" TEXT="OUTPUT">
<node ID="_Freemind_Link_851180815" TEXT="SampleID (string)"/>
<node ID="_Freemind_Link_1445993966" TEXT="Diagnostic (boolean)"/>
<node ID="_Freemind_Link_1293775540" TEXT="Score (number)"/>
<node ID="_Freemind_Link_1436387195" TEXT="SampleCellNumber"/>
</node>
</node>
</node>
<node ID="_Freemind_Link_471837120" TEXT="Cluster" STYLE="bubble" POSITION="right">
<cloud/>
<node ID="_Freemind_Link_401033813" COLOR="#ff0000" TEXT="getGridJob(GET)">
<node ID="_Freemind_Link_372130853" TEXT="INPUT">
<node ID="_Freemind_Link_542459810" TEXT="EndpointID (string)"/>
</node>
<node ID="_Freemind_Link_108129482" TEXT="OUTPUT">
<node ID="_Freemind_Link_489081334" TEXT="Image (zip)">
<node ID="_Freemind_Link_515026440" TEXT="GridID"/>
<node ID="_Freemind_Link_288919224" TEXT="Grid image"/>
</node>
</node>
</node>
<node ID="_Freemind_Link_226365965" COLOR="#ff0000" TEXT="storeGridResult(POST)">
<node ID="_Freemind_Link_206603998" TEXT="INPUT">
<node ID="_Freemind_Link_1899018679" TEXT="GridID (string)"/>
<node ID="_Freemind_Link_323918871" TEXT="GridValue (number)"/>
</node>
<node ID="_Freemind_Link_793038151" TEXT="OUTPUT">
<node ID="_Freemind_Link_1572406532" TEXT="Response (json)">
<node ID="_Freemind_Link_895821644" TEXT="Value stored"/>
<node ID="_Freemind_Link_962524091" TEXT="Unkown Endpoint"/>
</node>
</node>
</node>
<node ID="_Freemind_Link_357766610" COLOR="#0033ff" TEXT="getSampleJob (GET)">
<node ID="_Freemind_Link_1145631833" TEXT="INPUT">
<node ID="_Freemind_Link_962008366" TEXT="EndpointID (string)"/>
</node>
<node ID="_Freemind_Link_884207834" TEXT="OUTPUT">
<node ID="_Freemind_Link_1203696702" TEXT="Image (zip)">
<node ID="_Freemind_Link_1378351276" TEXT="Metadata">
<node ID="_Freemind_Link_1367208700" TEXT="SampleID"/>
<node ID="_Freemind_Link_1916224620" TEXT="GridValue"/>
<node ID="_Freemind_Link_147027675" TEXT="SampleCellNumber"/>
</node>
<node ID="_Freemind_Link_1722390855" TEXT="Sample Image"/>
</node>
</node>
</node>
<node ID="_Freemind_Link_1157868820" COLOR="#0033ff" TEXT="storeSampleResult (POST)" STYLE="bubble">
<node ID="_Freemind_Link_56870223" TEXT="INPUT">
<node ID="_Freemind_Link_1368653502" TEXT="EndpointID (string)"/>
<node ID="_Freemind_Link_1016537208" TEXT="SampleID (sting)"/>
<node TEXT="Diagnostic (boolean)"/>
<node ID="_Freemind_Link_441330896" TEXT="Score (numeric)"/>
</node>
<node ID="_Freemind_Link_552524601" TEXT="OUTPUT">
<node ID="_Freemind_Link_1385655063" TEXT="Response (json)">
<node ID="_Freemind_Link_428747128" TEXT="Value stored"/>
<node ID="_Freemind_Link_793644609" TEXT="Unkown Endpoint"/>
</node>
</node>
</node>
</node>
<node ID="_Freemind_Link_62308715" TEXT="SMS Server" STYLE="bubble" POSITION="right">
<cloud/>
<node ID="_Freemind_Link_1701904039" COLOR="#0033ff" TEXT="getResult (GET)" FOLDED="true">
<node ID="_Freemind_Link_1024900798" TEXT="INPUT">
<node ID="_Freemind_Link_1947013144" TEXT="EndPointID (string)"/>
</node>
<node ID="_Freemind_Link_1904459506" TEXT="OUTPUT">
<node ID="_Freemind_Link_767712823" TEXT="SampleID (string)"/>
<node ID="_Freemind_Link_1395385576" TEXT="Diagnostic (boolean)"/>
<node ID="_Freemind_Link_627816609" TEXT="Score (number)"/>
<node ID="_Freemind_Link_1206949567" TEXT="SampleCellNumber (string)"/>
</node>
</node>
</node>
<node ID="_Freemind_Link_1630940693" TEXT="Queue" FOLDED="true" POSITION="left">
<font NAME="SansSerif" SIZE="12"/>
<icon BUILTIN="wizard"/>
<node TEXT="Jobs (DB)"/>
<node TEXT="File storage (FS)"/>
</node>
</node>
</map>
