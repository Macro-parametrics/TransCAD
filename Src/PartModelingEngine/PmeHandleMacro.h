#pragma once

#define PME_PART2HANDLE(x) static_cast<PmeHPart>(x)
#define PME_HANDLE2PART(x) static_cast<PmePart *>(x)

#define PME_FEATURE2HANDLE(x) static_cast<PmeHFeature>(static_cast<PmeFeature *>(x))
#define PME_HANDLE2FEATURE(x) static_cast<PmeFeature *>(x)

#define PME_FEATURES2HANDLE(x) static_cast<PmeHFeatures>(x)
#define PME_HANDLE2FEATURES(x) static_cast<PmeFeatures *>(x)

#define PME_UPDATEINFOLIST2HANDLE(x) static_cast<PmeHUpdateInfo>(x)
#define PME_HANDLE2UPDATEINFOLIST(x) static_cast<PmeUpdateInfoList *>(x)

#define PME_EXPLICITMODELHANDLE(x) static_cast<PmeHExplicitModel>(static_cast<PmeExplicitModel *>(x))
#define PME_HANDLE2EXPLICITMODEL(x) static_cast<PmeExplicitModel *>(x)

#define PME_EXPLICITMODELOBJECT2HANDLE(x) static_cast<PmeHExplicitModelObject>(static_cast<PmeExplicitModelObject *>(x))
#define PME_HANDLE2EXPLICITMODELOBJECT(x) static_cast<PmeExplicitModelObject *>(x)

#define PME_EXPLICITMODELOBJECTS2HANDLE(x) static_cast<PmeHExplicitModelObjects>(x)
#define PME_HANDLE2EXPLICITMODELOBJECTS(x) static_cast<PmeHExplicitModelObjectList *>(x)

#define PME_REFERENCE2HANDLE(x) static_cast<PmeHReference>(static_cast<PmeReference *>(x))
#define PME_HANDLE2REFERENCE(x) static_cast<PmeReference *>(x)

#define PME_REFERENCES2HANDLE(x) static_cast<PmeHReferences>(x)
#define PME_HANDLE2REFERENCES(x) static_cast<PmeReferences *>(x)

#define PME_STDSKETCHEDITOR2HANDLE(x) static_cast<PmeHStdSketchEditor>(x)
#define PME_HANDLE2STDSKETCHEDITOR(x) static_cast<PmeStdSketchEditor *>(x)

#define PME_STDSKETCHGEOMETRY2HANDLE(x) static_cast<PmeHStdSketchGeometry>(static_cast<PmeStdSketchGeometry *>(x))
#define PME_HANDLE2STDSKETCHGEOMETRY(x) static_cast<PmeStdSketchGeometry *>(x)

#define PME_STDSKETCHGEOMETRIES2HANDLE(x) static_cast<PmeHStdSketchGeometries>(x)
#define PME_HANDLE2STDSKETCHGEOMETRIES(x) static_cast<PmeStdSketchGeometries *>(x)

#define PME_STDSKETCHORIGIN2HANDLE(x) static_cast<PmeHStdSketchOrigin>(x)
#define PME_HANDLE2STDSKETCHORIGIN(x) static_cast<PmeStdSketchOrigin *>(x)

#define PME_STDSKETCHHDIRECTION2HANDLE(x) static_cast<PmeHStdSketchHDirection>(x)
#define PME_HANDLE2STDSKETCHHDIRECTION(x) static_cast<PmeStdSketchHDirection *>(x)

#define PME_STDSKETCHVDIRECTION2HANDLE(x) static_cast<PmeHStdSketchVDirection>(x)
#define PME_HANDLE2STDSKETCHVDIRECTION(x) static_cast<PmeStdSketchVDirection *>(x)

#define PME_SOLID2HANDLE(x) static_cast<PmeHSolid>(x)
#define PME_HANDLE2SOLID(x) static_cast<PmeSolid *>(x)

#define PME_FACES2HANDLE(x) static_cast<PmeHFaces>(x)
#define PME_HANDLE2FACES(x) static_cast<PmeFaces *>(x)

#define PME_FACE2HANDLE(x) static_cast<PmeHFace>(x)
#define PME_HANDLE2FACE(x) static_cast<PmeFace *>(x)

#define PME_EDGES2HANDLE(x) static_cast<PmeHEdges>(x)
#define PME_HANDLE2EDGES(x) static_cast<PmeEdges *>(x)

#define PME_EDGE2HANDLE(x) static_cast<PmeHEdge>(x)
#define PME_HANDLE2EDGE(x) static_cast<PmeEdge *>(x)

#define PME_VERTICES2HANDLE(x) static_cast<PmeHVertices>(x)
#define PME_HANDLE2VERTICES(x) static_cast<PmeVertices *>(x)

#define PME_VERTEX2HANDLE(x) static_cast<PmeHVertex>(x)
#define PME_HANDLE2VERTEX(x) static_cast<PmeVertex *>(x)


// PmeStdSketchConstraint
#define PME_STDSKETCHCONSTRAINT2HANDLE(x) static_cast<PmeHStdSketchConstraint>(static_cast<PmeStdSketchConstraint *>(x))
#define PME_HANDLE2STDSKETCHCONSTRAINT(x) static_cast<PmeStdSketchConstraint *>(x)

#define PME_STDSKETCHCONSTRAINTS2HANDLE(x) static_cast<PmeHStdSketchConstraints>(static_cast<PmeStdSketchConstraints *>(x))
#define PME_HANDLE2STDSKETCHCONSTRAINTS(x) static_cast<PmeStdSketchConstraints *>(x)


// Assembler
#define PME_ASSEMBLY2HANDLE(x) static_cast<PmeHAssembly>(x)
#define PME_HANDLE2ASSEMBLY(x) static_cast<PmeAssembly *>(x)

#define PME_COMPONENT2HANDLE(x) static_cast<PmeHComponent>(x)
#define PME_HANDLE2COMPONENT(x) static_cast<PmeComponent *>(x)

#define PME_STDASSEMBLYCONSTRAINT2HANDLE(x) static_cast<PmeHStdAssemblyConstraint>(static_cast<PmeStdAssemblyConstraint *>(x))
#define PME_HANDLE2STDASSEMBLYCONSTRAINT(x) static_cast<PmeStdAssemblyConstraint *>(x)

#define PME_STDASSEMBLYCONSTRAINTS2HANDLE(x) static_cast<PmeHStdAssemblyConstraints>(static_cast<PmeStdAssemblyConstraints *>(x))
#define PME_HANDLE2STDASSEMBLYCONSTRAINTS(x) static_cast<PmeStdAssemblyConstraints *>(x)