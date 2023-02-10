<!-- CPLEX Solution file CPX_XML_VERSION 1.2 -->
<!-- Copyright IBM Corporation 2005, 2017. All Rights Reserved. -->
<xsl:stylesheet version="1.0"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="CPLEXSolution">
  <html><head><title>CPLEX Solution Report</title></head>
    <body>
      <xsl:apply-templates/>
    </body>
  </html>
</xsl:template>

<xsl:template match="CPLEXSolution/header">
  <h2>Solution Report for <xsl:value-of select="@problemName"/></h2>
  <table summary="Solution Header" border="1" cellpadding="6">
    <tr><td><b>Solution Status</b></td>
        <td><xsl:value-of select="@solutionStatusString"/></td>
    </tr>
    <tr><td><b>Solution Type</b></td>
        <td><xsl:value-of select="@solutionTypeString"/></td>
    </tr>
    <tr><td><b>Objective Value</b></td>
        <td><xsl:value-of select="@objectiveValue"/></td>
    </tr>
    <xsl:for-each select="@solutionMethodString">
       <tr><td><b>Solution Method</b></td>
           <td><xsl:value-of select="."/></td>
       </tr>
    </xsl:for-each>
    <xsl:for-each select="@primalFeasible">
       <tr><td><b>Primal Feasible</b></td>
           <td><xsl:value-of select="."/></td>
       </tr>
    </xsl:for-each>
    <xsl:for-each select="@dualFeasible">
       <tr><td><b>Dual Feasible</b></td>
           <td><xsl:value-of select="."/></td>
       </tr>
    </xsl:for-each>
    <xsl:for-each select="@simplexIterations">
       <tr><td><b>Simplex Iterations</b></td>
           <td><xsl:value-of select="."/></td>
       </tr>
    </xsl:for-each>
    <xsl:for-each select="@barrierIterations">
       <tr><td><b>Barrier Iterations</b></td>
           <td><xsl:value-of select="."/></td>
       </tr>
    </xsl:for-each>
    <xsl:for-each select="@MIPNodes">
       <tr><td><b>Nodes</b></td>
           <td><xsl:value-of select="."/></td>
       </tr>
    </xsl:for-each>
    <xsl:for-each select="@MIPIterations">
       <tr><td><b>Iterations</b></td>
           <td><xsl:value-of select="."/></td>
       </tr>
    </xsl:for-each>
  </table>
</xsl:template>


<xsl:template match="CPLEXSolution/quality">
  <br> </br>
  <table summary="Solution Quality" border="1" cellpadding="6">
    <tr>
      <th colspan="2"><b>Solution Quality</b></th>
    </tr>
    <tr>
       <th><b><xsl:text>Name</xsl:text></b></th>
       <th><b><xsl:text>Value</xsl:text></b></th>
    </tr>
    <xsl:for-each select="@*">
      <tr>
        <td align="left"><xsl:value-of select="name()"/></td>
        <td align="right"><xsl:value-of select="."/></td>
      </tr>
    </xsl:for-each>
  </table>
</xsl:template>

<xsl:template match="CPLEXSolution/linearConstraints">
  <br> </br>
  <table summary="Linear Constraints" border="1" cellpadding="6">
    <tr>
      <th colspan="4"><b>Linear Constraints</b></th>
    </tr>
    <tr>
       <th><b><xsl:text>Name</xsl:text></b></th>
       <th><b><xsl:text>Status</xsl:text></b></th>
       <th><b><xsl:text>Slack Value</xsl:text></b></th>
       <th><b><xsl:text>Dual Value</xsl:text></b></th>
    </tr>
    <xsl:for-each select="constraint">
      <tr>
        <td align="left"><xsl:value-of select="@name"/></td>
        <td align="left"><xsl:value-of select="@status"/></td>
        <td align="right"><xsl:value-of select="@slack"/></td>
        <td align="right"><xsl:value-of select="@dual"/></td> 
      </tr>
    </xsl:for-each>
  </table>
</xsl:template>

<xsl:template match="CPLEXSolution/quadraticConstraints">
  <br> </br>
  <table summary="Quadratic Constraints" border="1" cellpadding="6">
    <tr>
      <th colspan="2"><b>Quadratic Constraints</b></th>
    </tr>
    <tr>
       <th><b><xsl:text>Name</xsl:text></b></th>
       <th><b><xsl:text>Slack Value</xsl:text></b></th>
    </tr>
    <xsl:for-each select="constraint">
      <tr>
        <td align="left"><xsl:value-of select="@name"/></td>
        <td align="right"><xsl:value-of select="@slack"/></td> 
      </tr>
    </xsl:for-each>
  </table>
</xsl:template>

<xsl:template match="CPLEXSolution/indicatorConstraints">
  <br> </br>
  <table summary="Indicator Constraints" border="1" cellpadding="6">
    <tr>
      <th colspan="2"><b>Indicator Constraints</b></th>
    </tr>
    <tr>
       <th><b><xsl:text>Name</xsl:text></b></th>
       <th><b><xsl:text>Slack Value</xsl:text></b></th>
    </tr>
    <xsl:for-each select="constraint">
      <tr>
        <td align="left"><xsl:value-of select="@name"/></td>
        <td align="right"><xsl:value-of select="@slack"/></td> 
      </tr>
    </xsl:for-each>
  </table>
</xsl:template>

<xsl:template match="CPLEXSolution/variables">
  <br> </br>
  <table summary="Variables" border="1" cellpadding="6">
    <tr>
      <th colspan="4"><b>Variables</b></th>
    </tr>
    <tr>
       <th><b><xsl:text>Name</xsl:text></b></th>
       <th><b><xsl:text>Status</xsl:text></b></th>
       <th><b><xsl:text>Value</xsl:text></b></th>
       <th><b><xsl:text>Reduced Cost</xsl:text></b></th>
    </tr>
    <xsl:for-each select="variable">
      <tr>
        <td align="left"><xsl:value-of select="@name"/></td>
        <td align="left"><xsl:value-of select="@status"/></td>
        <td align="right"><xsl:value-of select="@value"/></td> 
        <td align="right"><xsl:value-of select="@reducedCost"/></td> 
      </tr>
    </xsl:for-each>
  </table>
</xsl:template>

</xsl:stylesheet>
