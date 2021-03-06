<?xml version="1.0"?> 
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:my="http://my.com">
<xsl:output method="xml" omit-xml-declaration="yes" />

<!-- XSLT - grouping-separator & grouping-size attributes -->
<!-- Created : Khalil Jabrane -->
<!-- Date: 04/18/2000 -->

	<xsl:template match="/">
        <H1><xsl:text>XSLT - Numbering - Rounding and conversion to number of value attribute</xsl:text></H1>
        <xsl:text>simple format : </xsl:text><xsl:number value="-2147483648" grouping-separator="," grouping-size="3"/><BR/>
        <xsl:text>space as grouping separator : </xsl:text><xsl:number value="-100000" grouping-separator="  " grouping-size="2"/><BR/>
        <xsl:text>grouping-size of zero : </xsl:text><xsl:number value="-100000" grouping-separator="," grouping-size="0"/><BR/>
        <xsl:text>empty grouping separator : </xsl:text><xsl:number value="-100000" grouping-separator="" grouping-size="3"/><BR/>
        <xsl:text>large grouping-separator : </xsl:text><xsl:number value="-100000" grouping-separator="                                                            " grouping-size="1"/><BR/>	
        <xsl:number value="-100000" format="&#x0e51;" grouping-separator="                                                            " grouping-size="1"/><BR/>
        <xsl:text>negative grouping size : </xsl:text><xsl:number value="-2147483648" grouping-separator="," grouping-size="-15"/><BR/>
        <xsl:text>large grouping size : </xsl:text><xsl:number value="-2147483648" grouping-separator="," grouping-size="10000000000"/><BR/>
        <xsl:text>In conjunction with lots of zero padding : </xsl:text><xsl:number value="-2147483648" format="0000000000000000000000000000001" grouping-separator="," grouping-size="3"/>
	</xsl:template>
   
</xsl:stylesheet>  
